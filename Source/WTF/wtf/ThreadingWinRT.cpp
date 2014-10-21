/*
 * Copyright (C) 2007, 2008 Apple Inc. All rights reserved.
 * Copyright (C) 2009 Google Inc. All rights reserved.
 * Copyright (C) 2009 Torch Mobile, Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer. 
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution. 
 * 3.  Neither the name of Apple Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "Threading.h"

#include "DateMath.h"
#include "dtoa.h"
#include "dtoa/cached-powers.h"

#include "MainThread.h"
#include "ThreadFunctionInvocation.h"
#include <windows.h>
#include <wtf/CurrentTime.h>
#include <wtf/HashMap.h>
#include <wtf/MathExtras.h>
#include <wtf/OwnPtr.h>
#include <wtf/PassOwnPtr.h>
#include <wtf/RandomNumberSeed.h>
#include <wtf/WTFThreadData.h>

#include "ThreadSpecific.h"

namespace WTF {

	class StdThreadState {
		WTF_MAKE_FAST_ALLOCATED;
	public:
		enum JoinableState {
			Joinable, // The default thread state. The thread can be joined on.
			Detached // The thread has been detached and can no longer be joined on. At this point, the thread must take care of cleaning up after itself.
		};

		// Currently all threads created by WTF start out as joinable.
		StdThreadState(std::thread *threadInstance)
			: m_joinableState(Joinable)
			, m_didExit(false)
			, m_threadInstance(threadInstance)
		{
			ASSERT(threadInstance);
			m_stdThreadID = threadInstance->get_id();
		}

		// Constructor when we don't have an std::thread, which would happen if we
		// didn't create the thread ourselves
		StdThreadState(std::thread::id threadID)
			: m_joinableState(Joinable)
			, m_didExit(false)
			, m_threadInstance(0)
			, m_stdThreadID(threadID)
		{
		}

		JoinableState joinableState() { return m_joinableState; }
		std::thread* threadInstance() { return m_threadInstance; }
		std::thread::id stdThreadID() { return m_stdThreadID; }
		void didBecomeDetached() { m_joinableState = Detached; }
		void didExit() { m_didExit = true; }
		bool hasExited() { return m_didExit; }

	private:
		JoinableState m_joinableState;
		bool m_didExit;
		std::thread* m_threadInstance;
		std::thread::id m_stdThreadID;
	};

static Mutex& threadMapMutex()
{
    static Mutex mutex;
    return mutex;
}

void initializeThreading()
{
    static bool isInitialized;
    
    if (isInitialized)
        return;

    isInitialized = true;

    WTF::double_conversion::initialize();
    // StringImpl::empty() does not construct its static string in a threadsafe fashion,
    // so ensure it has been initialized from here.
    StringImpl::empty();
    threadMapMutex();
    initializeRandomNumberGenerator();
    wtfThreadData();
    s_dtoaP5Mutex = new Mutex;
    initializeDates();
}

typedef HashMap<ThreadIdentifier, OwnPtr<StdThreadState>> ThreadMap;

static ThreadMap& threadMap()
{
	static ThreadMap map;
    return map;
}

static ThreadIdentifier identifierByStdThreadID(const std::thread::id& id)
{
	MutexLocker locker(threadMapMutex());

	ThreadMap::iterator i = threadMap().begin();
	for (; i != threadMap().end(); ++i) {
		if ((i->value->stdThreadID() == id) && !i->value->hasExited())
			return i->key;
	}

	return 0;
}

static ThreadIdentifier establishIdentifierForStdThreadState(StdThreadState* threadState)
{
	ASSERT(threadState);
	ASSERT(!identifierByStdThreadID(threadState->stdThreadID()));
	MutexLocker locker(threadMapMutex());
	static ThreadIdentifier identifierCount = 1;
	threadMap().add(identifierCount, adoptPtr(threadState));
	return identifierCount++;
}

static ThreadIdentifier establishIdentifierForStdThread(std::thread* threadInstance)
{
	return establishIdentifierForStdThreadState(new StdThreadState(threadInstance));
}

static ThreadIdentifier establishIdentifierForStdThreadID(std::thread::id stdThreadID)
{
	return establishIdentifierForStdThreadState(new StdThreadState(stdThreadID));
}

static std::thread* stdThreadForIdentifierWithLockAlreadyHeld(ThreadIdentifier id)
{
	return threadMap().get(id)->threadInstance();
}

static _declspec(thread) ThreadIdentifier currentThreadID = 0;

static void* wtfThreadEntryPoint(void* param)
{
	// Balanced by .leakPtr() in createThreadInternal.
	OwnPtr<ThreadFunctionInvocation> invocation = adoptPtr(static_cast<ThreadFunctionInvocation*>(param));
	invocation->function(invocation->data);

	ThreadSpecificThreadExit();

	ThreadIdentifier currentThreadId = identifierByStdThreadID(std::this_thread::get_id());
	{
		MutexLocker locker(threadMapMutex());
		StdThreadState* state = threadMap().get(currentThreadId);
		ASSERT(state);
		state->didExit();

		if (state->joinableState() != StdThreadState::Joinable)
			threadMap().remove(currentThreadId);
	}

	return 0;
}

ThreadIdentifier createThreadInternal(ThreadFunction entryPoint, void* data, const char*)
{
	OwnPtr<ThreadFunctionInvocation> invocation = adoptPtr(new ThreadFunctionInvocation(entryPoint, data));
	std::thread* threadInstance;
	try {
		threadInstance = new std::thread(wtfThreadEntryPoint, invocation.get());
	}
	catch (...) {
		LOG_ERROR("Failed to create std::thread at entry point %p with data %p", wtfThreadEntryPoint, invocation.get());
		return 0;
	}

	// Balanced by adoptPtr() in wtfThreadEntryPoint.
	ThreadFunctionInvocation* leakedInvocation = invocation.leakPtr();
	UNUSED_PARAM(leakedInvocation);

	return establishIdentifierForStdThread(threadInstance);
}

void initializeCurrentThreadInternal(const char* threadName)
{
	UNUSED_PARAM(threadName);

	currentThreadID = identifierByStdThreadID(std::this_thread::get_id());
	ASSERT(currentThreadID);
}

int waitForThreadCompletion(ThreadIdentifier threadID)
{
	std::thread* threadInstance;
	ASSERT(threadID);

	{
		// We don't want to lock across the call to join, since that can block our thread and cause deadlock.
		MutexLocker locker(threadMapMutex());
		threadInstance = stdThreadForIdentifierWithLockAlreadyHeld(threadID);
		ASSERT(threadInstance);
	}

	int joinResult = 0;
	try {
		threadInstance->join();
	}
	catch (...) {
		LOG_ERROR("ThreadIdentifier %u was unable to be joined. Error %d: %s", threadID);
		joinResult = 1;
	}

	MutexLocker locker(threadMapMutex());
	StdThreadState* state = threadMap().get(threadID);
	ASSERT(state);
	ASSERT(state->joinableState() == StdThreadState::Joinable);

	// The thread has already exited, so clean up after it.
	ASSERT(state->hasExited());
	threadMap().remove(threadID);

	return joinResult;
}

void detachThread(ThreadIdentifier threadID)
{
	ASSERT(threadID);

	MutexLocker locker(threadMapMutex());
	std::thread *threadInstance = stdThreadForIdentifierWithLockAlreadyHeld(threadID);
	ASSERT(threadInstance);

	try {
		threadInstance->detach();
	}
	catch (...) {
		LOG_ERROR("ThreadIdentifier %u was unable to be detached.", threadID);
	}

	StdThreadState* state = threadMap().get(threadID);
	ASSERT(state);
	if (state->hasExited())
		threadMap().remove(threadID);
	else
		threadMap().get(threadID)->didBecomeDetached();
}


void yield()
{
	std::this_thread::yield();
}

ThreadIdentifier currentThread()
{
	if (currentThreadID)
		return currentThreadID;

	// Not a WTF-created thread, and we won't have access to std::thread, but
	// the identifier can still be used for comparison purposes
	ThreadIdentifier id = identifierByStdThreadID(std::this_thread::get_id());
	if (!id) {
		id = establishIdentifierForStdThreadID(std::this_thread::get_id());
	}
	return id;
}

Mutex::Mutex()
{
    m_mutex.m_recursionCount = 0;
    InitializeCriticalSectionEx(&m_mutex.m_internalMutex, 0, 0);
}

Mutex::~Mutex()
{
    DeleteCriticalSection(&m_mutex.m_internalMutex);
}

void Mutex::lock()
{
    EnterCriticalSection(&m_mutex.m_internalMutex);
    ++m_mutex.m_recursionCount;
}
    
bool Mutex::tryLock()
{
    // This method is modeled after the behavior of pthread_mutex_trylock,
    // which will return an error if the lock is already owned by the
    // current thread.  Since the primitive Win32 'TryEnterCriticalSection'
    // treats this as a successful case, it changes the behavior of several
    // tests in WebKit that check to see if the current thread already
    // owned this mutex (see e.g., IconDatabase::getOrCreateIconRecord)
    DWORD result = TryEnterCriticalSection(&m_mutex.m_internalMutex);
    
    if (result != 0) {       // We got the lock
        // If this thread already had the lock, we must unlock and
        // return false so that we mimic the behavior of POSIX's
        // pthread_mutex_trylock:
        if (m_mutex.m_recursionCount > 0) {
            LeaveCriticalSection(&m_mutex.m_internalMutex);
            return false;
        }

        ++m_mutex.m_recursionCount;
        return true;
    }

    return false;
}

void Mutex::unlock()
{
    ASSERT(m_mutex.m_recursionCount);
    --m_mutex.m_recursionCount;
    LeaveCriticalSection(&m_mutex.m_internalMutex);
}

bool PlatformCondition::timedWait(PlatformMutex& mutex, DWORD durationMilliseconds)
{
    // Enter the wait state.
    DWORD res = WaitForSingleObjectEx(m_blockLock, INFINITE, false);
    ASSERT_UNUSED(res, res == WAIT_OBJECT_0);
    ++m_waitersBlocked;
    res = ReleaseSemaphore(m_blockLock, 1, 0);
    ASSERT_UNUSED(res, res);

    --mutex.m_recursionCount;
    LeaveCriticalSection(&mutex.m_internalMutex);

    // Main wait - use timeout.
    bool timedOut = (WaitForSingleObjectEx(m_blockQueue, durationMilliseconds, false) == WAIT_TIMEOUT);

    res = WaitForSingleObjectEx(m_unblockLock, INFINITE, false);
    ASSERT_UNUSED(res, res == WAIT_OBJECT_0);

    int signalsLeft = m_waitersToUnblock;

    if (m_waitersToUnblock)
        --m_waitersToUnblock;
    else if (++m_waitersGone == (INT_MAX / 2)) { // timeout/canceled or spurious semaphore
        // timeout or spurious wakeup occured, normalize the m_waitersGone count
        // this may occur if many calls to wait with a timeout are made and
        // no call to notify_* is made
        res = WaitForSingleObjectEx(m_blockLock, INFINITE, false);
        ASSERT_UNUSED(res, res == WAIT_OBJECT_0);
        m_waitersBlocked -= m_waitersGone;
        res = ReleaseSemaphore(m_blockLock, 1, 0);
        ASSERT_UNUSED(res, res);
        m_waitersGone = 0;
    }

    res = ReleaseMutex(m_unblockLock);
    ASSERT_UNUSED(res, res);

    if (signalsLeft == 1) {
        res = ReleaseSemaphore(m_blockLock, 1, 0); // Open the gate.
        ASSERT_UNUSED(res, res);
    }

    EnterCriticalSection (&mutex.m_internalMutex);
    ++mutex.m_recursionCount;

    return !timedOut;
}

void PlatformCondition::signal(bool unblockAll)
{
    unsigned signalsToIssue = 0;

    DWORD res = WaitForSingleObjectEx(m_unblockLock, INFINITE, false);
    ASSERT_UNUSED(res, res == WAIT_OBJECT_0);

    if (m_waitersToUnblock) { // the gate is already closed
        if (!m_waitersBlocked) { // no-op
            res = ReleaseMutex(m_unblockLock);
            ASSERT_UNUSED(res, res);
            return;
        }

        if (unblockAll) {
            signalsToIssue = m_waitersBlocked;
            m_waitersToUnblock += m_waitersBlocked;
            m_waitersBlocked = 0;
        } else {
            signalsToIssue = 1;
            ++m_waitersToUnblock;
            --m_waitersBlocked;
        }
    } else if (m_waitersBlocked > m_waitersGone) {
        res = WaitForSingleObjectEx(m_blockLock, INFINITE, false); // Close the gate.
        ASSERT_UNUSED(res, res == WAIT_OBJECT_0);
        if (m_waitersGone != 0) {
            m_waitersBlocked -= m_waitersGone;
            m_waitersGone = 0;
        }
        if (unblockAll) {
            signalsToIssue = m_waitersBlocked;
            m_waitersToUnblock = m_waitersBlocked;
            m_waitersBlocked = 0;
        } else {
            signalsToIssue = 1;
            m_waitersToUnblock = 1;
            --m_waitersBlocked;
        }
    } else { // No-op.
        res = ReleaseMutex(m_unblockLock);
        ASSERT_UNUSED(res, res);
        return;
    }

    res = ReleaseMutex(m_unblockLock);
    ASSERT_UNUSED(res, res);

    if (signalsToIssue) {
        res = ReleaseSemaphore(m_blockQueue, signalsToIssue, 0);
        ASSERT_UNUSED(res, res);
    }
}

static const long MaxSemaphoreCount = static_cast<long>(~0UL >> 1);

ThreadCondition::ThreadCondition()
{
    m_condition.m_waitersGone = 0;
    m_condition.m_waitersBlocked = 0;
    m_condition.m_waitersToUnblock = 0;
    m_condition.m_blockLock = CreateSemaphoreEx(0, 1, 1, 0, 0, SEMAPHORE_ALL_ACCESS);
    m_condition.m_blockQueue = CreateSemaphoreEx(0, 0, MaxSemaphoreCount, 0, 0, SEMAPHORE_ALL_ACCESS);
    m_condition.m_unblockLock = CreateMutexEx(0, 0, 0, MUTEX_ALL_ACCESS);

    if (!m_condition.m_blockLock || !m_condition.m_blockQueue || !m_condition.m_unblockLock) {
        if (m_condition.m_blockLock)
            CloseHandle(m_condition.m_blockLock);
        if (m_condition.m_blockQueue)
            CloseHandle(m_condition.m_blockQueue);
        if (m_condition.m_unblockLock)
            CloseHandle(m_condition.m_unblockLock);
    }
}

ThreadCondition::~ThreadCondition()
{
    CloseHandle(m_condition.m_blockLock);
    CloseHandle(m_condition.m_blockQueue);
    CloseHandle(m_condition.m_unblockLock);
}

void ThreadCondition::wait(Mutex& mutex)
{
    m_condition.timedWait(mutex.impl(), INFINITE);
}

bool ThreadCondition::timedWait(Mutex& mutex, double absoluteTime)
{
    DWORD interval = absoluteTimeToWaitTimeoutInterval(absoluteTime);

    if (!interval) {
        // Consider the wait to have timed out, even if our condition has already been signaled, to
        // match the pthreads implementation.
        return false;
    }

    return m_condition.timedWait(mutex.impl(), interval);
}

void ThreadCondition::signal()
{
    m_condition.signal(false); // Unblock only 1 thread.
}

void ThreadCondition::broadcast()
{
    m_condition.signal(true); // Unblock all threads.
}

DWORD absoluteTimeToWaitTimeoutInterval(double absoluteTime)
{
    double currentTime = WTF::currentTime();

    // Time is in the past - return immediately.
    if (absoluteTime < currentTime)
        return 0;

    // Time is too far in the future (and would overflow unsigned long) - wait forever.
    if (absoluteTime - currentTime > static_cast<double>(INT_MAX) / 1000.0)
        return INFINITE;

    return static_cast<DWORD>((absoluteTime - currentTime) * 1000.0);
}

} // namespace WTF

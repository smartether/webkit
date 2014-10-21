/*
 * Copyright (C) 2010 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "RunLoop.h"

#include <locale.h>
#include <wtf/CurrentTime.h>

namespace WTF {


void RunLoop::run()
{
	current().m_dispatcher->ProcessEvents(Windows::UI::Core::CoreProcessEventsOption::ProcessOneAndAllPending);
}

void RunLoop::stop()
{
	m_dispatcher->StopProcessEvents();
}

RunLoop::RunLoop()
	: m_dispatcher(Windows::UI::Core::CoreWindow::GetForCurrentThread()->Dispatcher)
{
    
}

RunLoop::~RunLoop()
{
    // FIXME: Tear down the work item queue here.
}

void RunLoop::wakeUp()
{
	static auto priority = Windows::UI::Core::CoreDispatcherPriority::Normal;
	auto callback = ref new Windows::UI::Core::DispatchedHandler([this]() {
		performWork();
	});
	Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(priority, callback);
}

// RunLoop::Timer

RunLoop::TimerBase::TimerBase(RunLoop& runLoop)
    : m_runLoop(runLoop)
	, m_timer(ref new Windows::UI::Xaml::DispatcherTimer())
{

}

RunLoop::TimerBase::~TimerBase()
{
    stop();
}

void RunLoop::TimerBase::start(double nextFireInterval, bool repeat)
{
	m_eventToken = m_timer->Tick += ref new Windows::Foundation::EventHandler<Platform::Object^>([this, repeat](Platform::Object^, Platform::Object^) {
		fired();
		if (!repeat)
			stop();
	});

	Windows::Foundation::TimeSpan interval;
	interval.Duration = nextFireInterval * 1000.0;
	m_timer->Interval = interval;
	m_timer->Start();
}

void RunLoop::TimerBase::stop()
{
	m_timer->Stop();
	m_timer->Tick -= m_eventToken;
}

bool RunLoop::TimerBase::isActive() const
{
	return m_timer->IsEnabled;
}

} // namespace WTF

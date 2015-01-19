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

#include <wrl/wrappers/corewrappers.h>

namespace WTF {

using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml;

void RunLoop::run()
{
    CoreDispatcher^ dispatcher = reinterpret_cast<CoreDispatcher^>(current().m_dispatcher.Get());
    dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessOneAndAllPending);
}

void RunLoop::stop()
{
    CoreDispatcher^ dispatcher = reinterpret_cast<CoreDispatcher^>(m_dispatcher.Get());
    dispatcher->StopProcessEvents();
}

RunLoop::RunLoop()
    : m_dispatcher(reinterpret_cast<ABI::Windows::UI::Core::ICoreDispatcher*>(CoreWindow::GetForCurrentThread()->Dispatcher))
{

}

RunLoop::~RunLoop()
{
    // FIXME: Tear down the work item queue here.
}

void RunLoop::wakeUp()
{
    static auto priority = CoreDispatcherPriority::Normal;
    auto callback = ref new DispatchedHandler([this]() {
        performWork();
    });
    Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(priority, callback);
}

// RunLoop::Timer

RunLoop::TimerBase::TimerBase(RunLoop& runLoop)
    : m_runLoop(runLoop)
{
    Windows::Foundation::ActivateInstance(Microsoft::WRL::Wrappers::HStringReference(RuntimeClass_Windows_UI_Xaml_DispatcherTimer).Get(), m_timer.GetAddressOf());
}

RunLoop::TimerBase::~TimerBase()
{
    stop();
}

void RunLoop::TimerBase::start(double nextFireInterval, bool repeat)
{
    DispatcherTimer^ timer = reinterpret_cast<DispatcherTimer^>(m_timer.Get());
    Windows::Foundation::EventRegistrationToken eventToken = timer->Tick += ref new Windows::Foundation::EventHandler<Platform::Object^>([this, repeat](Platform::Object^, Platform::Object^) {
        fired();
        if (!repeat)
            stop();
    });

    m_eventToken = { eventToken.Value };

    Windows::Foundation::TimeSpan interval;
    interval.Duration = nextFireInterval * 1000.0;
    timer->Interval = interval;
    timer->Start();
}

void RunLoop::TimerBase::stop()
{
    m_timer->Stop();
    m_timer->remove_Tick(m_eventToken);
}

bool RunLoop::TimerBase::isActive() const
{
    boolean isEnabled;
    m_timer->get_IsEnabled(&isEnabled);
    return isEnabled;
}

} // namespace WTF

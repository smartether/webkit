#include "config.h"
#include <wtf/text/WTFString.h>

#if PLATFORM(WINRT)

#include <Winstring.h>

namespace WTF {

String::String(HSTRING str)
{
    if (!str || WindowsGetStringLen(str) == 0)
        return;

    UINT32 length;
    PCWSTR rawBuffer = WindowsGetStringRawBuffer(str, &length);
    m_impl = StringImpl::create(rawBuffer, length);
}

Microsoft::WRL::Wrappers::HString String::createHString() const
{
    if (!m_impl)
        return Microsoft::WRL::Wrappers::HString();

    return m_impl->createHString();
}

}

#endif // PLATFORM(WINRT)

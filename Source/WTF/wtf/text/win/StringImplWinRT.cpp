#include "config.h"
#include <wtf/text/StringImpl.h>

#if PLATFORM(WINRT)

#include <Winstring.h>
#include <StringBuffer.h>

namespace WTF {

Microsoft::WRL::Wrappers::HString StringImpl::createHString() const
{
    if (!m_length)
        return Microsoft::WRL::Wrappers::HString();

    HSTRING hstring = nullptr;

    if (!is8Bit()) {
        WindowsCreateString(characters16(), m_length, &hstring);
    } else {
        StringBuffer<UChar> buffer(m_length);
        for (unsigned i = 0; i < m_length; ++i)
            buffer[i] = m_data8[i];
        WindowsCreateString(buffer.characters(), m_length, &hstring);
    }

    ASSERT(hstring);
    Microsoft::WRL::Wrappers::HString hstringWrapper;
    hstringWrapper.Attach(hstring);
    return hstringWrapper;
}

}

#endif // PLATFORM(WINRT)

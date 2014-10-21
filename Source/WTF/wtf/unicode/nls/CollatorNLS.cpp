/*
 * Copyright (C) 2008, 2014 Apple Inc. All rights reserved.
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
#include "Collator.h"

#include <wtf/text/StringView.h>

namespace WTF {

Collator::Collator(const char* locale, bool shouldSortLowercaseFirst)
	: m_locale(strdup(locale))
	, m_shouldSortLowercaseFirst(shouldSortLowercaseFirst)
{
	size_t localeSize = strlen(locale) + 1;
	wchar_t* wcstring = new wchar_t[localeSize];
	mbstowcs_s(nullptr, wcstring, localeSize, locale, _TRUNCATE);
	m_collator = reinterpret_cast<UCollator*>(wcstring);
}

Collator::~Collator()
{
	free(m_locale);
	wchar_t* wcstring = reinterpret_cast<wchar_t*>(m_collator);
	delete[] wcstring;
}

int Collator::collate(StringView a, StringView b) const
{
	return CompareStringEx(reinterpret_cast<LPCWSTR>(m_collator), 0, a.upconvertedCharacters(), a.length(), b.upconvertedCharacters(), b.length(), nullptr, nullptr, 0);
}

int Collator::collateUTF8(const char* a, const char* b) const
{
    return collate(String::fromUTF8(a), String::fromUTF8(b));
}

}

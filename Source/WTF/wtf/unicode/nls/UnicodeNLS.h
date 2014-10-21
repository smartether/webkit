#ifndef WTF_UnicodeNls_h
#define WTF_UnicodeNls_h

#include <stdint.h>
#include <wchar.h>
#include <windows.h>
#include <wtf/unicode/ScriptCodesFromICU.h>
#include <wtf/unicode/UnicodeMacrosFromICU.h>

typedef wchar_t UChar;
typedef uint32_t UChar32;

namespace WTF {
namespace Unicode {

enum Direction {
    LeftToRight,
    RightToLeft,
    EuropeanNumber,
    EuropeanNumberSeparator,
    EuropeanNumberTerminator,
    ArabicNumber,
    CommonNumberSeparator,
    BlockSeparator,
    SegmentSeparator,
    WhiteSpaceNeutral,
    OtherNeutral,
    LeftToRightEmbedding,
    LeftToRightOverride,
    RightToLeftArabic,
    RightToLeftEmbedding,
    RightToLeftOverride,
    PopDirectionalFormat,
    NonSpacingMark,
    BoundaryNeutral
};

enum DecompositionType {
    DecompositionNone,
    DecompositionCanonical,
    DecompositionCompat,
    DecompositionCircle,
    DecompositionFinal,
    DecompositionFont,
    DecompositionFraction,
    DecompositionInitial,
    DecompositionIsolated,
    DecompositionMedial,
    DecompositionNarrow,
    DecompositionNoBreak,
    DecompositionSmall,
    DecompositionSquare,
    DecompositionSub,
    DecompositionSuper,
    DecompositionVertical,
    DecompositionWide
};

enum CharCategory {
    NoCategory = 0,
    Other_NotAssigned = U_MASK(0),
    Letter_Uppercase = U_MASK(1),
    Letter_Lowercase = U_MASK(2),
    Letter_Titlecase = U_MASK(3),
    Letter_Modifier = U_MASK(4),
    Letter_Other = U_MASK(5),

    Mark_NonSpacing = U_MASK(6),
    Mark_Enclosing = U_MASK(7),
    Mark_SpacingCombining = U_MASK(8),

    Number_DecimalDigit = U_MASK(9),
    Number_Letter = U_MASK(10),
    Number_Other = U_MASK(11),

    Separator_Space = U_MASK(12),
    Separator_Line = U_MASK(13),
    Separator_Paragraph = U_MASK(14),

    Other_Control = U_MASK(15),
    Other_Format = U_MASK(16),
    Other_PrivateUse = U_MASK(17),
    Other_Surrogate = U_MASK(18),

    Punctuation_Dash = U_MASK(19),
    Punctuation_Open = U_MASK(20),
    Punctuation_Close = U_MASK(21),
    Punctuation_Connector = U_MASK(22),
    Punctuation_Other = U_MASK(23),

    Symbol_Math = U_MASK(24),
    Symbol_Currency = U_MASK(25),
    Symbol_Modifier = U_MASK(26),
    Symbol_Other = U_MASK(27),

    Punctuation_InitialQuote = U_MASK(28),
    Punctuation_FinalQuote = U_MASK(29)
};


WTF_EXPORT_PRIVATE CharCategory category(UChar32);
WTF_EXPORT_PRIVATE unsigned char combiningClass(UChar32);
WTF_EXPORT_PRIVATE Direction direction(UChar32);
WTF_EXPORT_PRIVATE DecompositionType decompositionType(UChar32);
WTF_EXPORT_PRIVATE bool requiresComplexContextForWordBreaking(UChar32);
WTF_EXPORT_PRIVATE UChar32 mirroredChar(UChar32);

inline bool isAlphanumeric(UChar c) { return !!iswalnum(c); }
inline bool isDigit(UChar c) { return !!iswdigit(c); }
inline bool isLetter(UChar c) { return !!iswalpha(c); }
inline bool isLower(UChar c) { return !!iswlower(c); }
inline bool isPrintableChar(UChar c) { return !!iswprint(c); }
inline bool isPunct(UChar c) { return !!iswpunct(c); }
inline bool isSpace(UChar c) { return !!iswspace(c); }
inline bool isUpper(UChar c) { return !!iswupper(c); }

inline bool isArabicChar(UChar32 c) { return c >= 0x0600 && c <= 0x06ff; }
inline bool isSeparatorSpace(UChar32 c) { return category(c) == Separator_Space; }

inline UChar foldCase(UChar c) { return towlower(c); }
inline UChar toLower(UChar c) { return towlower(c); }
inline UChar toUpper(UChar c) { return towupper(c); }
inline UChar toTitleCase(UChar c) { return towupper(c); }

WTF_EXPORT_PRIVATE int foldCase(UChar* result, int resultLength, const UChar* source, int sourceLength, bool* isError);
WTF_EXPORT_PRIVATE int toLower(UChar* result, int resultLength, const UChar* source, int sourceLength, const char* locale, bool* isError);
WTF_EXPORT_PRIVATE int toUpper(UChar* result, int resultLength, const UChar* source, int sourceLength, const char* locale, bool* isError);

inline int umemcasecmp(const UChar* a, const UChar* b, int len)
{
	return CompareStringEx(LOCALE_NAME_SYSTEM_DEFAULT, LINGUISTIC_IGNORECASE, a, len, b, len, NULL, NULL, 0) - 2;
}

} // namespace Unicode
} // namespace WTF

#endif // WTF_UnicodeNls_h

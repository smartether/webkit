/* ANSI-C code produced by gperf version 2.7.2 */
/* Command-line: gperf -a -L ANSI-C -E -C -c -o -t -k '*' -NfindProp -Hhash_prop -Wwordlist_prop -D -s 2 cssproperties.gperf  */
/* This file is automatically generated from cssproperties.in by makeprop, do not edit */
/* Copyright 1999 W. Bastian */
#include "cssproperties.h"
struct props {
    const char *name;
    int id;
};
/* maximum key range = 1772, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash_prop (register const char *str, register unsigned int len)
{
  static const unsigned short asso_values[] =
    {
      1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777,
      1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777,
      1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777,
      1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777,
      1777, 1777, 1777, 1777, 1777,    0, 1777, 1777, 1777, 1777,
      1777,   10, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777,
      1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777,
      1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777,
      1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777,
      1777, 1777, 1777, 1777, 1777, 1777, 1777,    5,   20,    0,
         0,    0,  185,  135,    0,    0,   10,  120,    0,   20,
       445,    0,   90,   30,    0,   15,    0,  140,   25,  335,
       340,   85,    0, 1777, 1777, 1777, 1777, 1777, 1777, 1777,
      1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777,
      1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777,
      1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777,
      1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777,
      1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777,
      1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777,
      1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777,
      1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777,
      1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777,
      1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777,
      1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777,
      1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777, 1777,
      1777, 1777, 1777, 1777, 1777, 1777
    };
  register int hval = len;

  switch (hval)
    {
      default:
      case 32:
        hval += asso_values[(unsigned char)str[31]];
      case 31:
        hval += asso_values[(unsigned char)str[30]];
      case 30:
        hval += asso_values[(unsigned char)str[29]];
      case 29:
        hval += asso_values[(unsigned char)str[28]];
      case 28:
        hval += asso_values[(unsigned char)str[27]];
      case 27:
        hval += asso_values[(unsigned char)str[26]];
      case 26:
        hval += asso_values[(unsigned char)str[25]];
      case 25:
        hval += asso_values[(unsigned char)str[24]];
      case 24:
        hval += asso_values[(unsigned char)str[23]];
      case 23:
        hval += asso_values[(unsigned char)str[22]];
      case 22:
        hval += asso_values[(unsigned char)str[21]];
      case 21:
        hval += asso_values[(unsigned char)str[20]];
      case 20:
        hval += asso_values[(unsigned char)str[19]];
      case 19:
        hval += asso_values[(unsigned char)str[18]];
      case 18:
        hval += asso_values[(unsigned char)str[17]];
      case 17:
        hval += asso_values[(unsigned char)str[16]];
      case 16:
        hval += asso_values[(unsigned char)str[15]];
      case 15:
        hval += asso_values[(unsigned char)str[14]];
      case 14:
        hval += asso_values[(unsigned char)str[13]];
      case 13:
        hval += asso_values[(unsigned char)str[12]];
      case 12:
        hval += asso_values[(unsigned char)str[11]];
      case 11:
        hval += asso_values[(unsigned char)str[10]];
      case 10:
        hval += asso_values[(unsigned char)str[9]];
      case 9:
        hval += asso_values[(unsigned char)str[8]];
      case 8:
        hval += asso_values[(unsigned char)str[7]];
      case 7:
        hval += asso_values[(unsigned char)str[6]];
      case 6:
        hval += asso_values[(unsigned char)str[5]];
      case 5:
        hval += asso_values[(unsigned char)str[4]];
      case 4:
        hval += asso_values[(unsigned char)str[3]];
      case 3:
        hval += asso_values[(unsigned char)str[2]];
      case 2:
        hval += asso_values[(unsigned char)str[1]];
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval;
}

#ifdef __GNUC__
__inline
#endif
const struct props *
findProp (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 139,
      MIN_WORD_LENGTH = 3,
      MAX_WORD_LENGTH = 32,
      MIN_HASH_VALUE = 5,
      MAX_HASH_VALUE = 1776
    };

  static const struct props wordlist_prop[] =
    {
      {"color", CSS_PROP_COLOR},
      {"clear", CSS_PROP_CLEAR},
      {"size", CSS_PROP_SIZE},
      {"border", CSS_PROP_BORDER},
      {"border-color", CSS_PROP_BORDER_COLOR},
      {"bottom", CSS_PROP_BOTTOM},
      {"border-bottom", CSS_PROP_BORDER_BOTTOM},
      {"border-bottom-color", CSS_PROP_BORDER_BOTTOM_COLOR},
      {"top", CSS_PROP_TOP},
      {"clip", CSS_PROP_CLIP},
      {"border-top", CSS_PROP_BORDER_TOP},
      {"list-style", CSS_PROP_LIST_STYLE},
      {"border-top-color", CSS_PROP_BORDER_TOP_COLOR},
      {"border-style", CSS_PROP_BORDER_STYLE},
      {"right", CSS_PROP_RIGHT},
      {"height", CSS_PROP_HEIGHT},
      {"border-collapse", CSS_PROP_BORDER_COLLAPSE},
      {"visibility", CSS_PROP_VISIBILITY},
      {"cursor", CSS_PROP_CURSOR},
      {"border-right", CSS_PROP_BORDER_RIGHT},
      {"border-right-color", CSS_PROP_BORDER_RIGHT_COLOR},
      {"border-bottom-style", CSS_PROP_BORDER_BOTTOM_STYLE},
      {"scrollbar-track-color", CSS_PROP_SCROLLBAR_TRACK_COLOR},
      {"opacity", CSS_PROP_OPACITY},
      {"left", CSS_PROP_LEFT},
      {"quotes", CSS_PROP_QUOTES},
      {"float", CSS_PROP_FLOAT},
      {"display", CSS_PROP_DISPLAY},
      {"scrollbar-3dlight-color", CSS_PROP_SCROLLBAR_3DLIGHT_COLOR},
      {"border-left", CSS_PROP_BORDER_LEFT},
      {"empty-cells", CSS_PROP_EMPTY_CELLS},
      {"border-left-color", CSS_PROP_BORDER_LEFT_COLOR},
      {"border-top-style", CSS_PROP_BORDER_TOP_STYLE},
      {"page", CSS_PROP_PAGE},
      {"scrollbar-face-color", CSS_PROP_SCROLLBAR_FACE_COLOR},
      {"table-layout", CSS_PROP_TABLE_LAYOUT},
      {"border-right-style", CSS_PROP_BORDER_RIGHT_STYLE},
      {"list-style-image", CSS_PROP_LIST_STYLE_IMAGE},
      {"list-style-type", CSS_PROP_LIST_STYLE_TYPE},
      {"border-left-style", CSS_PROP_BORDER_LEFT_STYLE},
      {"-khtml-user-select", CSS_PROP__KHTML_USER_SELECT},
      {"scrollbar-highlight-color", CSS_PROP_SCROLLBAR_HIGHLIGHT_COLOR},
      {"width", CSS_PROP_WIDTH},
      {"-khtml-marquee", CSS_PROP__KHTML_MARQUEE},
      {"border-width", CSS_PROP_BORDER_WIDTH},
      {"scrollbar-arrow-color", CSS_PROP_SCROLLBAR_ARROW_COLOR},
      {"border-bottom-width", CSS_PROP_BORDER_BOTTOM_WIDTH},
      {"scrollbar-shadow-color", CSS_PROP_SCROLLBAR_SHADOW_COLOR},
      {"-khtml-user-drag", CSS_PROP__KHTML_USER_DRAG},
      {"direction", CSS_PROP_DIRECTION},
      {"-khtml-marquee-style", CSS_PROP__KHTML_MARQUEE_STYLE},
      {"white-space", CSS_PROP_WHITE_SPACE},
      {"-khtml-marquee-speed", CSS_PROP__KHTML_MARQUEE_SPEED},
      {"border-top-width", CSS_PROP_BORDER_TOP_WIDTH},
      {"border-right-width", CSS_PROP_BORDER_RIGHT_WIDTH},
      {"max-height", CSS_PROP_MAX_HEIGHT},
      {"scrollbar-darkshadow-color", CSS_PROP_SCROLLBAR_DARKSHADOW_COLOR},
      {"overflow", CSS_PROP_OVERFLOW},
      {"border-left-width", CSS_PROP_BORDER_LEFT_WIDTH},
      {"position", CSS_PROP_POSITION},
      {"orphans", CSS_PROP_ORPHANS},
      {"caption-side", CSS_PROP_CAPTION_SIDE},
      {"page-break-after", CSS_PROP_PAGE_BREAK_AFTER},
      {"line-height", CSS_PROP_LINE_HEIGHT},
      {"outline", CSS_PROP_OUTLINE},
      {"page-break-before", CSS_PROP_PAGE_BREAK_BEFORE},
      {"outline-color", CSS_PROP_OUTLINE_COLOR},
      {"-khtml-user-modify", CSS_PROP__KHTML_USER_MODIFY},
      {"min-height", CSS_PROP_MIN_HEIGHT},
      {"margin", CSS_PROP_MARGIN},
      {"counter-reset", CSS_PROP_COUNTER_RESET},
      {"unicode-bidi", CSS_PROP_UNICODE_BIDI},
      {"vertical-align", CSS_PROP_VERTICAL_ALIGN},
      {"font", CSS_PROP_FONT},
      {"font-size", CSS_PROP_FONT_SIZE},
      {"font-stretch", CSS_PROP_FONT_STRETCH},
      {"margin-bottom", CSS_PROP_MARGIN_BOTTOM},
      {"padding", CSS_PROP_PADDING},
      {"list-style-position", CSS_PROP_LIST_STYLE_POSITION},
      {"widows", CSS_PROP_WIDOWS},
      {"-khtml-flow-mode", CSS_PROP__KHTML_FLOW_MODE},
      {"outline-style", CSS_PROP_OUTLINE_STYLE},
      {"letter-spacing", CSS_PROP_LETTER_SPACING},
      {"margin-top", CSS_PROP_MARGIN_TOP},
      {"text-shadow", CSS_PROP_TEXT_SHADOW},
      {"max-width", CSS_PROP_MAX_WIDTH},
      {"border-spacing", CSS_PROP_BORDER_SPACING},
      {"padding-bottom", CSS_PROP_PADDING_BOTTOM},
      {"-khtml-box-pack", CSS_PROP__KHTML_BOX_PACK},
      {"-apple-text-size-adjust", CSS_PROP__APPLE_TEXT_SIZE_ADJUST},
      {"font-style", CSS_PROP_FONT_STYLE},
      {"margin-right", CSS_PROP_MARGIN_RIGHT},
      {"-apple-line-clamp", CSS_PROP__APPLE_LINE_CLAMP},
      {"padding-top", CSS_PROP_PADDING_TOP},
      {"z-index", CSS_PROP_Z_INDEX},
      {"margin-left", CSS_PROP_MARGIN_LEFT},
      {"-khtml-marquee-direction", CSS_PROP__KHTML_MARQUEE_DIRECTION},
      {"text-decoration", CSS_PROP_TEXT_DECORATION},
      {"min-width", CSS_PROP_MIN_WIDTH},
      {"text-decoration-color", CSS_PROP_TEXT_DECORATION_COLOR},
      {"padding-right", CSS_PROP_PADDING_RIGHT},
      {"font-size-adjust", CSS_PROP_FONT_SIZE_ADJUST},
      {"page-break-inside", CSS_PROP_PAGE_BREAK_INSIDE},
      {"padding-left", CSS_PROP_PADDING_LEFT},
      {"background", CSS_PROP_BACKGROUND},
      {"-khtml-margin-collapse", CSS_PROP__KHTML_MARGIN_COLLAPSE},
      {"background-color", CSS_PROP_BACKGROUND_COLOR},
      {"-khtml-marquee-repetition", CSS_PROP__KHTML_MARQUEE_REPETITION},
      {"content", CSS_PROP_CONTENT},
      {"text-overflow", CSS_PROP_TEXT_OVERFLOW},
      {"-khtml-border-vertical-spacing", CSS_PROP__KHTML_BORDER_VERTICAL_SPACING},
      {"-khtml-margin-bottom-collapse", CSS_PROP__KHTML_MARGIN_BOTTOM_COLLAPSE},
      {"outline-width", CSS_PROP_OUTLINE_WIDTH},
      {"text-align", CSS_PROP_TEXT_ALIGN},
      {"font-family", CSS_PROP_FONT_FAMILY},
      {"-khtml-box-orient", CSS_PROP__KHTML_BOX_ORIENT},
      {"-khtml-box-direction", CSS_PROP__KHTML_BOX_DIRECTION},
      {"-khtml-margin-top-collapse", CSS_PROP__KHTML_MARGIN_TOP_COLLAPSE},
      {"-khtml-box-lines", CSS_PROP__KHTML_BOX_LINES},
      {"background-repeat", CSS_PROP_BACKGROUND_REPEAT},
      {"outline-offset", CSS_PROP_OUTLINE_OFFSET},
      {"text-transform", CSS_PROP_TEXT_TRANSFORM},
      {"word-spacing", CSS_PROP_WORD_SPACING},
      {"-khtml-box-flex", CSS_PROP__KHTML_BOX_FLEX},
      {"background-image", CSS_PROP_BACKGROUND_IMAGE},
      {"-khtml-box-align", CSS_PROP__KHTML_BOX_ALIGN},
      {"font-weight", CSS_PROP_FONT_WEIGHT},
      {"font-variant", CSS_PROP_FONT_VARIANT},
      {"-khtml-binding", CSS_PROP__KHTML_BINDING},
      {"text-indent", CSS_PROP_TEXT_INDENT},
      {"-khtml-marquee-increment", CSS_PROP__KHTML_MARQUEE_INCREMENT},
      {"-khtml-border-horizontal-spacing", CSS_PROP__KHTML_BORDER_HORIZONTAL_SPACING},
      {"-khtml-box-ordinal-group", CSS_PROP__KHTML_BOX_ORDINAL_GROUP},
      {"background-attachment", CSS_PROP_BACKGROUND_ATTACHMENT},
      {"-khtml-box-flex-group", CSS_PROP__KHTML_BOX_FLEX_GROUP},
      {"background-position", CSS_PROP_BACKGROUND_POSITION},
      {"counter-increment", CSS_PROP_COUNTER_INCREMENT},
      {"background-position-y", CSS_PROP_BACKGROUND_POSITION_Y},
      {"background-position-x", CSS_PROP_BACKGROUND_POSITION_X}
    };

  static const short lookup[] =
    {
       -1,  -1,  -1,  -1,  -1,   0,  -1,  -1,  -1,  -1,
        1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,   2,
       -1,  -1,  -1,  -1,  -1,  -1,   3,  -1,  -1,  -1,
       -1,  -1,   4,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,   5,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,   6,  -1,  -1,  -1,  -1,  -1,   7,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,   8,   9,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       10,  -1,  -1,  -1,  -1,  11,  12,  -1,  -1,  -1,
       -1,  -1,  13,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       14,  15,  -1,  -1,  -1,  16,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  17,  -1,  -1,  -1,  -1,
       -1,  18,  -1,  -1,  -1,  -1,  -1,  19,  -1,  -1,
       -1,  -1,  -1,  20,  -1,  -1,  -1,  -1,  -1,  21,
       -1,  -1,  -1,  -1,  -1,  -1,  22,  23,  -1,  24,
       -1,  25,  -1,  -1,  -1,  26,  -1,  -1,  -1,  -1,
       -1,  -1,  27,  -1,  -1,  -1,  -1,  -1,  28,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  29,  -1,  -1,  -1,
       -1,  30,  31,  -1,  -1,  -1,  32,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  33,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       34,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  35,  -1,  -1,
       -1,  -1,  -1,  36,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  37,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  38,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  39,  -1,  -1,  -1,  -1,  -1,  40,  -1,
       -1,  -1,  -1,  -1,  -1,  41,  -1,  -1,  -1,  -1,
       42,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  43,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  44,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  45,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  46,  -1,  -1,  47,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  48,  -1,  -1,  49,  50,  51,  -1,  -1,  -1,
       52,  53,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  54,  -1,
       55,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  56,  -1,  -1,  -1,
       -1,  -1,  -1,  57,  -1,  -1,  -1,  58,  59,  -1,
       -1,  -1,  60,  -1,  -1,  -1,  -1,  61,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  62,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  63,  64,  -1,  -1,  -1,  -1,  65,  66,  -1,
       -1,  -1,  -1,  67,  -1,  -1,  -1,  -1,  -1,  -1,
       68,  69,  -1,  70,  -1,  -1,  -1,  71,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  72,
       -1,  -1,  -1,  -1,  73,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  74,  -1,  -1,  75,  76,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  77,  -1,  78,  -1,  -1,  -1,  -1,  -1,
       -1,  79,  -1,  -1,  -1,  -1,  80,  -1,  81,  -1,
       -1,  -1,  -1,  -1,  82,  83,  84,  -1,  -1,  85,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  86,  -1,  -1,  -1,  -1,  87,
       88,  -1,  -1,  89,  -1,  -1,  -1,  -1,  -1,  -1,
       90,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  91,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  92,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  93,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  94,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  95,  -1,  -1,  96,  97,  -1,  -1,  -1,  98,
       -1,  99,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 100,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 101,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 102,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 103,  -1,  -1, 104,  -1, 105,  -1,  -1,
       -1, 106,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 107,  -1, 108, 109,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      110,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1, 111,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 112,  -1, 113, 114,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 115,  -1,  -1, 116,  -1,  -1,  -1,  -1,
       -1, 117,  -1,  -1,  -1,  -1, 118, 119,  -1,  -1,
       -1,  -1,  -1,  -1, 120,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1, 121,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1, 122,  -1,  -1,
      123, 124,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 125,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 126,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 127,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 128,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 129,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 130,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 131,  -1,  -1,  -1,  -1,  -1,  -1, 132,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 133,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 134,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1, 135,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 136,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1, 137,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1, 138
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash_prop (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register int index = lookup[key];

          if (index >= 0)
            {
              register const char *s = wordlist_prop[index].name;

              if (*str == *s && !strncmp (str + 1, s + 1, len - 1) && s[len] == '\0')
                return &wordlist_prop[index];
            }
        }
    }
  return 0;
}
static const char * const propertyList[] = {
"",
"background-color", 
"background-image", 
"background-repeat", 
"background-attachment", 
"background-position", 
"background-position-x", 
"background-position-y", 
"-khtml-binding", 
"border-collapse", 
"border-spacing", 
"-khtml-border-horizontal-spacing", 
"-khtml-border-vertical-spacing", 
"border-top-color", 
"border-right-color", 
"border-bottom-color", 
"border-left-color", 
"border-top-style", 
"border-right-style", 
"border-bottom-style", 
"border-left-style", 
"border-top-width", 
"border-right-width", 
"border-bottom-width", 
"border-left-width", 
"bottom", 
"-khtml-box-align", 
"-khtml-box-direction", 
"-khtml-box-flex", 
"-khtml-box-flex-group", 
"-khtml-box-lines", 
"-khtml-box-ordinal-group", 
"-khtml-box-orient", 
"-khtml-box-pack", 
"caption-side", 
"clear", 
"clip", 
"color", 
"content", 
"counter-increment", 
"counter-reset", 
"cursor", 
"direction", 
"display", 
"empty-cells", 
"float", 
"font-family", 
"font-size", 
"font-size-adjust", 
"font-stretch", 
"font-style", 
"font-variant", 
"font-weight", 
"height", 
"left", 
"letter-spacing", 
"-apple-line-clamp", 
"line-height", 
"list-style-image", 
"list-style-position", 
"list-style-type", 
"margin-top", 
"margin-right", 
"margin-bottom", 
"margin-left", 
"-khtml-margin-collapse", 
"-khtml-margin-top-collapse", 
"-khtml-margin-bottom-collapse", 
"-khtml-marquee", 
"-khtml-marquee-direction", 
"-khtml-marquee-increment", 
"-khtml-marquee-repetition", 
"-khtml-marquee-speed", 
"-khtml-marquee-style", 
"max-height", 
"max-width", 
"min-height", 
"min-width", 
"opacity", 
"orphans", 
"outline-color", 
"outline-offset", 
"outline-style", 
"outline-width", 
"overflow", 
"padding-top", 
"padding-right", 
"padding-bottom", 
"padding-left", 
"page", 
"page-break-after", 
"page-break-before", 
"page-break-inside", 
"position", 
"quotes", 
"right", 
"size", 
"table-layout", 
"text-align", 
"text-decoration", 
"text-decoration-color", 
"text-indent", 
"text-overflow", 
"text-shadow", 
"text-transform", 
"-apple-text-size-adjust", 
"top", 
"unicode-bidi", 
"-khtml-user-drag", 
"-khtml-user-modify", 
"-khtml-user-select", 
"vertical-align", 
"visibility", 
"white-space", 
"widows", 
"width", 
"word-spacing", 
"z-index", 
"background", 
"border", 
"border-color", 
"border-style", 
"border-top", 
"border-right", 
"border-bottom", 
"border-left", 
"border-width", 
"font", 
"list-style", 
"margin", 
"outline", 
"padding", 
"scrollbar-face-color", 
"scrollbar-shadow-color", 
"scrollbar-highlight-color", 
"scrollbar-3dlight-color", 
"scrollbar-darkshadow-color", 
"scrollbar-track-color", 
"scrollbar-arrow-color", 
"-khtml-flow-mode", 
    0
};
DOMString getPropertyName(unsigned short id)
{
    if(id >= CSS_PROP_TOTAL || id == 0)
      return DOMString();
    else
      return DOMString(propertyList[id]);
};


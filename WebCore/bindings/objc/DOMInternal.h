/*
 * Copyright (C) 2004-2006 Apple Computer, Inc.  All rights reserved.
 * Copyright (C) 2006 James G. Speth (speth@end.com)
 * Copyright (C) 2006 Samuel Weinig (sam.weinig@gmail.com)
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
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#import "DOM.h"

#import "Color.h"
#import "DOMAbstractView.h"
#import "DOMCSSPrimitiveValue.h"
#import "DOMCSSRule.h"
#import "DOMCSSStyleSheet.h"
#import "DOMCSSValue.h"
#import "DOMEvents.h"
#import "DOMHTMLOptionElement.h"
#import "DOMNode.h"
#import "DOMObject.h"
#import "DOMRGBColor.h"
#import "DOMStyleSheet.h"

#ifdef XPATH_SUPPORT
#import "DOMXPathNSResolver.h"
#endif // XPATH_SUPPORT

// Auto-generated internal interfaces
#import "DOMAttrInternal.h"
#import "DOMCDATASectionInternal.h"
#import "DOMCSSRuleListInternal.h"
#import "DOMCSSStyleDeclarationInternal.h"
#import "DOMCharacterDataInternal.h"
#import "DOMCommentInternal.h"
#import "DOMCounterInternal.h"
#import "DOMDOMImplementationInternal.h"
#import "DOMDocumentFragmentInternal.h"
#import "DOMDocumentInternal.h"
#import "DOMDocumentTypeInternal.h"
#import "DOMElementInternal.h"
#import "DOMEntityInternal.h"
#import "DOMEntityReferenceInternal.h"
#import "DOMHTMLAnchorElementInternal.h"
#import "DOMHTMLAreaElementInternal.h"
#import "DOMHTMLBRElementInternal.h"
#import "DOMHTMLBaseElementInternal.h"
#import "DOMHTMLBaseFontElementInternal.h"
#import "DOMHTMLBodyElementInternal.h"
#import "DOMHTMLButtonElementInternal.h"
#import "DOMHTMLCollectionInternal.h"
#import "DOMHTMLDListElementInternal.h"
#import "DOMHTMLDirectoryElementInternal.h"
#import "DOMHTMLDivElementInternal.h"
#import "DOMHTMLDocumentInternal.h"
#import "DOMHTMLElementInternal.h"
#import "DOMHTMLFieldSetElementInternal.h"
#import "DOMHTMLFontElementInternal.h"
#import "DOMHTMLFormElementInternal.h"
#import "DOMHTMLFrameElementInternal.h"
#import "DOMHTMLFrameSetElementInternal.h"
#import "DOMHTMLHRElementInternal.h"
#import "DOMHTMLHeadElementInternal.h"
#import "DOMHTMLHeadingElementInternal.h"
#import "DOMHTMLHtmlElementInternal.h"
#import "DOMHTMLIFrameElementInternal.h"
#import "DOMHTMLImageElementInternal.h"
#import "DOMHTMLInputElementInternal.h"
#import "DOMHTMLIsIndexElementInternal.h"
#import "DOMHTMLLIElementInternal.h"
#import "DOMHTMLLabelElementInternal.h"
#import "DOMHTMLLegendElementInternal.h"
#import "DOMHTMLLinkElementInternal.h"
#import "DOMHTMLMapElementInternal.h"
#import "DOMHTMLMenuElementInternal.h"
#import "DOMHTMLMetaElementInternal.h"
#import "DOMHTMLModElementInternal.h"
#import "DOMHTMLOListElementInternal.h"
#import "DOMHTMLObjectElementInternal.h"
#import "DOMHTMLOptGroupElementInternal.h"
#import "DOMHTMLOptionsCollectionInternal.h"
#import "DOMHTMLParagraphElementInternal.h"
#import "DOMHTMLParamElementInternal.h"
#import "DOMHTMLPreElementInternal.h"
#import "DOMHTMLQuoteElementInternal.h"
#import "DOMHTMLScriptElementInternal.h"
#import "DOMHTMLSelectElementInternal.h"
#import "DOMHTMLStyleElementInternal.h"
#import "DOMHTMLTableCaptionElementInternal.h"
#import "DOMHTMLTableCellElementInternal.h"
#import "DOMHTMLTableColElementInternal.h"
#import "DOMHTMLTableElementInternal.h"
#import "DOMHTMLTableRowElementInternal.h"
#import "DOMHTMLTableSectionElementInternal.h"
#import "DOMHTMLTextAreaElementInternal.h"
#import "DOMHTMLTitleElementInternal.h"
#import "DOMHTMLUListElementInternal.h"
#import "DOMMediaListInternal.h"
#import "DOMNamedNodeMapInternal.h"
#import "DOMNodeListInternal.h"
#import "DOMNotationInternal.h"
#import "DOMProcessingInstructionInternal.h"
#import "DOMRectInternal.h"
#import "DOMStyleSheetListInternal.h"
#import "DOMTextInternal.h"

#ifdef SVG_SUPPORT
#import "DOMSVGAngleInternal.h"
#import "DOMSVGElementInternal.h"
#import "DOMSVGLengthInternal.h"
#import "DOMSVGLengthListInternal.h"
#import "DOMSVGMatrixInternal.h"
#import "DOMSVGPathSegInternal.h"
#import "DOMSVGPathSegListInternal.h"
#import "DOMSVGTransformInternal.h"
#import "DOMSVGTransformListInternal.h"
#endif // SVG_SUPPORT

#ifdef XPATH_SUPPORT
#import "DOMXPathExpressionInternal.h"
#import "DOMXPathResultInternal.h"
#endif // XPATH_SUPPORT

namespace WebCore {
    class CSSPrimitiveValue;
    class CSSRule;
    class CSSStyleSheet;
    class CSSValue;
    class DOMWindow;
    class Event;
    class HTMLOptionElement;
    class Node;
    class NodeFilter;
    class NodeIterator;
    class Range;
    class StyleSheet;
    class TreeWalker;

#ifdef XPATH_SUPPORT
    class XPathNSResolver;
#endif // XPATH_SUPPORT

    typedef int ExceptionCode;
    typedef DOMWindow AbstractView;
}

// Core Internal Interfaces

@interface DOMObject (WebCoreInternal)
- (id)_init;
@end

@interface DOMNode (WebCoreInternal)
+ (DOMNode *)_nodeWith:(WebCore::Node *)impl;
- (WebCore::Node *)_node;
@end

// HTML Internal Interfaces

@interface DOMHTMLOptionElement (WebCoreInternal)
+ (DOMHTMLOptionElement *)_HTMLOptionElementWith:(WebCore::HTMLOptionElement *)impl;
- (WebCore::HTMLOptionElement *)_HTMLOptionElement;
@end

// CSS Internal Interfaces

@interface DOMCSSRule (WebCoreInternal)
+ (DOMCSSRule *)_CSSRuleWith:(WebCore::CSSRule *)impl;
@end

@interface DOMCSSValue (WebCoreInternal)
+ (DOMCSSValue *)_CSSValueWith:(WebCore::CSSValue *)impl;
@end

@interface DOMCSSPrimitiveValue (WebCoreInternal)
- (WebCore::CSSPrimitiveValue *)_CSSPrimitiveValue;
+ (DOMCSSPrimitiveValue *)_CSSPrimitiveValueWith:(WebCore::CSSValue *)impl;
@end

@interface DOMRGBColor (WebCoreInternal)
+ (DOMRGBColor *)_RGBColorWithRGB:(WebCore::RGBA32)value;
@end

@interface DOMCSSStyleSheet (WebCoreInternal)
+ (DOMCSSStyleSheet *)_CSSStyleSheetWith:(WebCore::CSSStyleSheet *)impl;
@end

// StyleSheets Internal Interfaces

@interface DOMStyleSheet (WebCoreInternal)
+ (DOMStyleSheet *)_styleSheetWith:(WebCore::StyleSheet *)impl;
@end

// Events Internal Interfaces

@interface DOMEvent (WebCoreInternal)
+ (DOMEvent *)_eventWith:(WebCore::Event *)impl;
- (WebCore::Event *)_event;
@end

// Range Internal Interfaces

@interface DOMRange (WebCoreInternal)
+ (DOMRange *)_rangeWith:(WebCore::Range *)impl;
- (WebCore::Range *)_range;
@end

// Traversal Internal Interfaces

@interface DOMNodeIterator (WebCoreInternal)
+ (DOMNodeIterator *)_nodeIteratorWith:(WebCore::NodeIterator *)impl filter:(id <DOMNodeFilter>)filter;
@end

@interface DOMTreeWalker (WebCoreInternal)
+ (DOMTreeWalker *)_treeWalkerWith:(WebCore::TreeWalker *)impl filter:(id <DOMNodeFilter>)filter;
@end

@interface DOMNodeFilter : DOMObject <DOMNodeFilter>
+ (DOMNodeFilter *)_nodeFilterWith:(WebCore::NodeFilter *)impl;
@end

// Views Internal Interfaces

@interface DOMAbstractView (WebCoreInternal)
+ (DOMAbstractView *)_abstractViewWith:(WebCore::AbstractView *)impl;
- (WebCore::AbstractView *)_abstractView;
@end

#ifdef XPATH_SUPPORT
// XPath Internal Interfaces

@interface DOMNativeXPathNSResolver : DOMObject <DOMXPathNSResolver>
+ (DOMNativeXPathNSResolver *)_xpathNSResolverWith:(WebCore::XPathNSResolver *)impl;
- (WebCore::XPathNSResolver *)_xpathNSResolver;
@end

#endif // XPATH_SUPPORT


// Helper functions for DOM wrappers and gluing to Objective-C

NSObject* getDOMWrapper(DOMObjectInternal*);
void addDOMWrapper(NSObject* wrapper, DOMObjectInternal*);

template <class Source> inline id getDOMWrapper(Source impl) { return getDOMWrapper(reinterpret_cast<DOMObjectInternal*>(impl)); }
template <class Source> inline void addDOMWrapper(NSObject* wrapper, Source impl) { addDOMWrapper(wrapper, reinterpret_cast<DOMObjectInternal*>(impl)); }
void removeDOMWrapper(DOMObjectInternal*);

void raiseDOMException(WebCore::ExceptionCode);

inline void raiseOnDOMError(WebCore::ExceptionCode ec) 
{
    if (ec) 
        raiseDOMException(ec);
}

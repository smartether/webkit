/*
 * Copyright (C) 2004, 2006 Apple Computer, Inc.  All rights reserved.
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

#ifndef htmlediting_h
#define htmlediting_h

#include <qptrlist.h>

class QString;

namespace WebCore {

class DOMString;
class DocumentImpl;
class ElementImpl;
class NodeImpl;
class Position;

const unsigned short NON_BREAKING_SPACE = 0xa0;

int maxDeepOffset(const NodeImpl*);
bool isAtomicNode(const NodeImpl*);

void rebalanceWhitespaceInTextNode(NodeImpl*, unsigned start, unsigned length);
DOMString& nonBreakingSpaceString();
void derefNodesInList(const QPtrList<NodeImpl>&);

//------------------------------------------------------------------------------------------

Position positionBeforeNode(const NodeImpl*);
Position positionAfterNode(const NodeImpl*);

bool isSpecialElement(const NodeImpl*);

ElementImpl* createDefaultParagraphElement(DocumentImpl*);
ElementImpl* createBreakElement(DocumentImpl*);

bool isTabSpanNode(const NodeImpl*);
bool isTabSpanTextNode(const NodeImpl*);
NodeImpl* tabSpanNode(const NodeImpl*);
Position positionBeforeTabSpan(const Position&);
ElementImpl* createTabSpanElement(DocumentImpl*, NodeImpl* tabTextNode = 0);
ElementImpl* createTabSpanElement(DocumentImpl*, QString* tabText);

bool isNodeRendered(const NodeImpl*);
bool isMailBlockquote(const NodeImpl*);
NodeImpl *nearestMailBlockquote(const NodeImpl*);

//------------------------------------------------------------------------------------------

bool isTableStructureNode(const NodeImpl*);
ElementImpl *createBlockPlaceholderElement(DocumentImpl*);

bool isFirstVisiblePositionInSpecialElement(const Position&);
Position positionBeforeContainingSpecialElement(const Position&);
bool isLastVisiblePositionInSpecialElement(const Position&);
Position positionAfterContainingSpecialElement(const Position&);
Position positionOutsideContainingSpecialElement(const Position&);

}

#endif

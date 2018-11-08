#pragma once
#include "NodeI.h"
class LinkNode : public NodeI
{
  public:
	friend class NodeCopier;
	friend class DecoratorVisitor;
	LinkNode(NodeI* reference);
	virtual NodeI *link(NodeI *Next);
	virtual StringIterator in(StringIterator it);
	virtual NodeI *accept(NodeVisitor *v);

  protected:
	NodeI *next_in;
};
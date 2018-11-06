#pragma once
#include "NodeI.h"
#include "DecoratorNode.h"

class Counter;
/**
 * @brief
 * Node which will surrond a counter node to make it behave in lazy mode (match as few as possible)
 */
class Lazy : public DecoratorNode
{
  public:
  	friend class NodeCopier;
	Lazy(Counter *begGrp);
	virtual ~Lazy();
	StringIterator in(StringIterator it);
	NodeI *link(NodeI *node);
	NodeI *getPred();
	virtual NodeI *accept(NodeVisitor *v);

protected:
	Counter *internGrp;
};

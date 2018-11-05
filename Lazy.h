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
	Lazy(Counter *begGrp);
	StringIterator in(StringIterator it);
	NodeI *link(NodeI *node);
	NodeI *getPred();

  protected:
	Counter *internGrp;
};

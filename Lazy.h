#pragma once
#include "NodeI.h"
#include "DecoratorNode.h"

class Counter;
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

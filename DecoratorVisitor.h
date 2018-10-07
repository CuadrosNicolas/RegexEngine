#pragma once
#include "NodeI.h"
#include "Counter.h"
#include "Lazy.h"
class DecoratorVisitor
{
	public:
	  DecoratorVisitor();
	  NodeI* visit(NodeI *node);
	  NodeI *visit(Counter *node);

};
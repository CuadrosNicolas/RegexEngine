#pragma once
#include "NodeI.h"
#include "Counter.h"
#include "Lazy.h"
#include "GroupEndNode.h"
class DecoratorVisitor
{
	public:
	  DecoratorVisitor();
	  NodeI* visit(NodeI *node);
	  NodeI *visit(Counter *node);
	  NodeI *visit(GroupEndNode *node);
};
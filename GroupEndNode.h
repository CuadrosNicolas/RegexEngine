#pragma once
#include "NodeI.h"
class GroupEndNode : public NodeI
{
	public:
	GroupEndNode(NodeI *previousGroupBegin);
	  StringIterator in(StringIterator it);
	  bool test(char c);
	  virtual NodeI* getPred();
	  NodeI *accept(DecoratorVisitor *v);
};
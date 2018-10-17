#pragma once
#include "NodeI.h"
class GroupEndNode : public NodeI
{
	public:
	GroupEndNode(NodeI *previousGroupBegin);
	  virtual StringIterator in(StringIterator it);
	  bool test(char c);
	  virtual NodeI* getPred() const;
	  NodeI *accept(DecoratorVisitor *v);
};

class NonCapturingGroupEndNode : public GroupEndNode
{
  public:
	NonCapturingGroupEndNode(NodeI *previousGroupBegin);
	StringIterator in(StringIterator it);
	NodeI *accept(DecoratorVisitor *v);
};
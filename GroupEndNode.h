#pragma once
#include "NodeI.h"

class GroupEndNode : public NodeI
{
	public:
		friend class NodeCopier;
		GroupEndNode(NodeI *previousGroupBegin);
	  virtual StringIterator in(StringIterator it);
	  bool test(char c);
	  virtual NodeI* getPred() const;
		NodeI *accept(NodeVisitor *v);
};

class NonCapturingGroupEndNode : public GroupEndNode
{
  public:
		friend class NodeCopier;
		NonCapturingGroupEndNode(NodeI *previousGroupBegin);
		StringIterator in(StringIterator it);
		NodeI *accept(NodeVisitor *v);
};
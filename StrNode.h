#pragma once
#include "NodeI.h"
#include "CharFunction.h"
class StrNode : public NodeI
{
	public:
		friend class NodeCopier;
		StrNode(std::string v);
		virtual bool test(char c);
		StringIterator in(StringIterator it);
		virtual NodeI* accept(NodeVisitor *v);
	protected:
		std::string value;
};

class StrNodeInsensitive : public NodeI
{
  public:
	friend class NodeCopier;
	StrNodeInsensitive(std::string v);
	virtual bool test(char c);
	bool testValue(char in,char c);
	StringIterator in(StringIterator it);
	virtual NodeI *accept(NodeVisitor *v);
	NodeI *getStrNode(std::string c, int F);
	protected : std::string value;
};

NodeI *getStrNode(std::string c, int F);
#pragma once
#include "NodeI.h"
#include "GroupEndNode.h"
#include "Counter.h"
#include "AssemblyNode.h"
#include "GroupBeginNode.h"
#include "EndNode.h"
#include "DecoratorNode.h"
#include "Lazy.h"
#include "SetNode.h"
#include "CharNode.h"
#include "StrNode.h"

class NodeVisitor
{
  public:
	NodeVisitor()
	{

	}
	virtual NodeI *visit(NodeI *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(Counter *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(SetNode *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(CharNode *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(StrNode *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(DecoratorNode *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(Lazy *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(CharNodeInsensitive *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(SetNodeInsensitive *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(GroupEndNode *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(NonCapturingGroupEndNode *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(GroupBeginNode *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(NonCapturingGroupBeginNode *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(LookAheadNode *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(NegLookAheadNode *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(BeginNode *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(EndNode *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(WordNode *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(NotWordNode *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(NumberNode *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(NotNumberNode *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(WhiteSpaceNode *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(NotWhiteSpaceNode *node)
	{
		return nullptr;
	}
	virtual NodeI *visit(DotNode *node)
	{
		return nullptr;
	}
};
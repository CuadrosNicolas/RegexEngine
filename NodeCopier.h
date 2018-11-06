#pragma once
#include "NodeVisitor.h"
#include <map>
class NodeCopier : public NodeVisitor
{
	public:
		NodeCopier();
		NodeI* BuildCopy(NodeI* node);
		virtual NodeI *visit(NodeI *node);
		virtual NodeI *visit(Counter *node);
		virtual NodeI *visit(SetNode *node);
		virtual NodeI *visit(CharNode *node);
		virtual NodeI *visit(DecoratorNode *node);
		virtual NodeI *visit(Lazy *node);
		virtual NodeI *visit(CharNodeInsensitive *node);
		virtual NodeI *visit(SetNodeInsensitive *node);
		virtual NodeI *visit(GroupEndNode *node);
		virtual NodeI *visit(NonCapturingGroupEndNode *node);
		virtual NodeI *visit(GroupBeginNode *node);
		virtual NodeI *visit(NonCapturingGroupBeginNode *node);
		virtual NodeI *visit(LookAheadNode *node);
		virtual NodeI *visit(NegLookAheadNode *node);
		virtual NodeI *visit(BeginNode *node);
		virtual NodeI *visit(EndNode *node);
		virtual NodeI *visit(WordNode *node);
		virtual NodeI *visit(NotWordNode *node);
		virtual NodeI *visit(NumberNode *node);
		virtual NodeI *visit(NotNumberNode *node);
		virtual NodeI *visit(WhiteSpaceNode *node);
		virtual NodeI *visit(NotWhiteSpaceNode *node);
		virtual NodeI *visit(DotNode *node);
	private:
		NodeI* out;
		NodeI* actual;
		std::map<NodeI*,NodeI*> corresponder;
};
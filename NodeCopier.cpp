#include "NodeCopier.h"

NodeCopier::NodeCopier()
{
	out = nullptr;
	corresponder = std::map<NodeI*,NodeI*>();
}
NodeI *NodeCopier::BuildCopy(NodeI *node)
{
	return node->accept(this);
}
NodeI *NodeCopier::visit(NodeI *node)
{
	return nullptr;
}
NodeI *NodeCopier::visit(Counter *node)
{
	if(corresponder.find(node)!= corresponder.end())
	{
		corresponder[node]->setNext(node->next->accept(this));
		return corresponder[node];
	}
	else
	{
		Counter *temp = new Counter(node->min, node->max);
		corresponder[node] = temp;
		temp->internNode = (node->internNode->accept(this));
		return temp;
	}
}
NodeI *NodeCopier::visit(SetNode *node)
{
	SetNode* temp = new SetNode();
	corresponder[node] = temp;
	temp->isNot = node->isNot;
	temp->charList = node->charList;
	temp->setList = node->setList;
	temp->setNext(node->getNext()->accept(this));
	return temp;
}
NodeI *NodeCopier::visit(CharNode *node)
{
	CharNode *temp = new CharNode(node->value);
	corresponder[node] = temp;
	temp->setNext(node->getNext()->accept(this));
	return temp;
}
NodeI *NodeCopier::visit(StrNode *node)
{
	StrNode *temp = new StrNode(node->value);
	corresponder[node] = temp;
	temp->setNext(node->getNext()->accept(this));
	return temp;
}
NodeI *NodeCopier::visit(DecoratorNode *node)
{
	return nullptr;
}
NodeI *NodeCopier::visit(Lazy *node)
{
	Lazy *temp = new Lazy(node->internGrp);
	corresponder[node] = temp;
	temp->setNext(node->getNext()->accept(this));
	return temp;
}
NodeI *NodeCopier::visit(CharNodeInsensitive *node)
{
	CharNodeInsensitive *temp = new CharNodeInsensitive(node->value);
	corresponder[node] = temp;
	temp->setNext(node->getNext()->accept(this));
	return temp;
}
NodeI *NodeCopier::visit(StrNodeInsensitive *node)
{
	StrNodeInsensitive *temp = new StrNodeInsensitive(node->value);
	corresponder[node] = temp;
	temp->setNext(node->getNext()->accept(this));
	return temp;
}
NodeI *NodeCopier::visit(SetNodeInsensitive *node)
{
	SetNodeInsensitive *temp = new SetNodeInsensitive();
	corresponder[node] = temp;
	temp->isNot = node->isNot;
	temp->charList = node->charList;
	temp->setList = node->setList;
	temp->setNext(node->getNext()->accept(this));
	return temp;
}
NodeI *NodeCopier::visit(GroupEndNode *node)
{
	GroupEndNode *temp = new GroupEndNode(corresponder[node->pred]);
	corresponder[node] = temp;
	temp->next = node->next,
	temp->setNext(node->getNext()->accept(this));
	return temp;
}
NodeI *NodeCopier::visit(NonCapturingGroupEndNode *node)
{
	NonCapturingGroupEndNode *temp = new NonCapturingGroupEndNode(corresponder[node->pred]);
	corresponder[node] = temp;
	temp->next = node->next,
	temp->setNext(node->getNext()->accept(this));
	return temp;
}
NodeI *NodeCopier::visit(GroupBeginNode *node)
{
	GroupBeginNode *temp = new GroupBeginNode();
	corresponder[node] = temp;
	for(auto t:node->children)
	{
		temp->children.push_back(t->accept(this));
	}
	return temp;
}
NodeI *NodeCopier::visit(NonCapturingGroupBeginNode *node)
{
	NonCapturingGroupBeginNode *temp = new NonCapturingGroupBeginNode();
	corresponder[node] = temp;
	for (auto t : node->children)
	{
		temp->children.push_back(t->accept(this));
	}
	return temp;
}
NodeI *NodeCopier::visit(LookAheadNode *node)
{

	LookAheadNode *temp = new LookAheadNode();
	corresponder[node] = temp;
	temp->next = node->next->accept(this);
	temp->next_in = node->next_in->accept(this);
	return temp;
}
NodeI *NodeCopier::visit(NegLookAheadNode *node)
{
	LookAheadNode *temp = new LookAheadNode();
	corresponder[node] = temp;
	temp->next = node->next->accept(this);
	temp->next_in = node->next_in->accept(this);
	return temp;
}
NodeI *NodeCopier::visit(BeginNode *node)
{
	BeginNode *temp = new BeginNode();
	corresponder[node] = temp;
	for (auto t : node->children)
	{
		temp->children.push_back(t->accept(this));
	}
	return temp;
}
NodeI *NodeCopier::visit(EndNode *node)
{
	EndNode* temp = new EndNode();
	corresponder[node] = temp;
	return temp;
}
NodeI *NodeCopier::visit(WordNode *node)
{
	WordNode *temp = new WordNode();
	corresponder[node] = temp;
	temp->setNext(node->getNext()->accept(this));
	return temp;
}
NodeI *NodeCopier::visit(NotWordNode *node)
{
	NotWordNode *temp = new NotWordNode();
	corresponder[node] = temp;
	temp->setNext(node->getNext()->accept(this));
	return temp;
}
NodeI *NodeCopier::visit(NumberNode *node)
{
	NumberNode *temp = new NumberNode();
	corresponder[node] = temp;
	temp->setNext(node->getNext()->accept(this));
	return temp;
}
NodeI *NodeCopier::visit(NotNumberNode *node)
{
	NotNumberNode *temp = new NotNumberNode();
	corresponder[node] = temp;
	temp->setNext(node->getNext()->accept(this));
	return temp;
}
NodeI *NodeCopier::visit(WhiteSpaceNode *node)
{
	WhiteSpaceNode *temp = new WhiteSpaceNode();
	corresponder[node] = temp;
	temp->setNext(node->getNext()->accept(this));
	return temp;
}
NodeI *NodeCopier::visit(NotWhiteSpaceNode *node)
{
	NotWhiteSpaceNode *temp = new NotWhiteSpaceNode();
	corresponder[node] = temp;
	temp->setNext(node->getNext()->accept(this));
	return temp;
}
NodeI *NodeCopier::visit(DotNode *node)
{
	DotNode *temp = new DotNode();
	corresponder[node] = temp;
	temp->setNext(node->getNext()->accept(this));
	return temp;
}
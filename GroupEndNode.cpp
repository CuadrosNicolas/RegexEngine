#include "GroupEndNode.h"
#include "DecoratorVisitor.h"
GroupEndNode::GroupEndNode(NodeI *previousGroupBegin)
{
	pred = previousGroupBegin;
}
StringIterator GroupEndNode::in(StringIterator it)
{
	it.backMatch();
	return next->in(it);
}
bool GroupEndNode::test(char c)
{
	return true;
}
NodeI* GroupEndNode::getPred()
{
	return pred;
}
NodeI *GroupEndNode::accept(DecoratorVisitor *v)
{
	return v->visit(this);
}

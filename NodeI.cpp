#include "NodeI.h"
#include "DecoratorVisitor.h"
bool NodeI::test(char c)
{
	return true;
}
StringIterator NodeI::in(StringIterator it) {
	if (!it.end())
	{
			return this->next->in(it + 1);
	}
	return it;
}

NodeI *NodeI::link(NodeI *Next)
{
	return this->next = Next;
}
NodeI *NodeI::getPred() const
{
	return pred;
}
NodeI *NodeI::getNext() const
{
	return next;
}
void NodeI::setPred(NodeI *n)
{
	pred = n;
}
void NodeI::setNext(NodeI *n)
{
	next = n;
}

NodeI *NodeI::accept(DecoratorVisitor *v)
{
	return v->visit(this);
}

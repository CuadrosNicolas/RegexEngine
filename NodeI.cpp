#include "NodeI.h"
#include "DecoratorVisitor.h"
NodeI::~NodeI()
{
	delete pred;
	delete next;
}
bool NodeI::test(char c)
{
	return true;
}
StringIterator NodeI::in(StringIterator it) {
	if (!it.end() && this->test(it.get()))
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

NodeI *NodeI::accept(NodeVisitor *v)
{
	return v->visit(this);
}

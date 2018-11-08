#include "LinkNode.h"
#include "NodeVisitor.h"
LinkNode::LinkNode(NodeI *reference)
{
	next_in = reference;
}
StringIterator LinkNode::in(StringIterator it)
{
	StringIterator nIt;
	if ((nIt = next_in->in(it)).isValid(false))
	{
		nIt.unvalid();
		return next->in(nIt);
	}
	return it;
}

NodeI *LinkNode::accept(NodeVisitor *v)
{
	return v->visit(this);
}
NodeI *LinkNode::link(NodeI *Next)
{
	return next = Next;
}
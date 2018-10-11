#include "GroupBeginNode.h"

GroupBeginNode::GroupBeginNode()
{

}
NodeI* GroupBeginNode::add(NodeI* next)
{
	children.push_back(next);
	return next;
}
NodeI* GroupBeginNode::link(NodeI* next)
{
	children.push_back(next);
	return next;
}
StringIterator GroupBeginNode::in(StringIterator it)
{
	StringIterator temp;
	StringIterator temp_in = it;
	temp_in.push();
	for(NodeI* node : children)
	{
		temp = node->in(temp_in);
		if(temp.isValid())
		{
			return temp;
		}

	}
	it.cleanLast();
	return it;
}
void GroupBeginNode::setPred(NodeI *n)
{
	pred = n;
}
void GroupBeginNode::setNext(NodeI *n)
{
	children.back() = n;
}
bool GroupBeginNode::test(char c)
{
	return true;
}

BeginNode::BeginNode() : GroupBeginNode()
{

}
StringIterator BeginNode::in(StringIterator it)
{
	StringIterator temp;
	StringIterator temp_in = it;
	for (NodeI *node : children)
	{
		temp = node->in(temp_in);
		if (temp.isValid())
		{
			return temp;
		}
	}
	return it;
}
#include "GroupBeginNode.h"

GroupBeginNode::GroupBeginNode()
{
	alreadyPush = false;
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
	//if(!alreadyPush)

		StringIterator temp_in = it;
		temp_in.push();
		alreadyPush = true;

	//else

		//it.addChild();
	for(NodeI* node : children)
	{
		temp = node->in(temp_in);
		if(temp.isValid())
		{
			return temp;
		}

	}
	return it;
}
void GroupBeginNode::setPred(NodeI *n)
{
	pred = n;
}
void GroupBeginNode::setNext(NodeI *n)
{
	children[0] = n;
}
bool GroupBeginNode::test(char c)
{
	return true;
}
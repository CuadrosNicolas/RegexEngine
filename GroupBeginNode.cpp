#include "GroupBeginNode.h"
#include "NodeVisitor.h"
#include "NodeCopier.h"
GroupBeginNode::GroupBeginNode()
{

}
GroupBeginNode::~GroupBeginNode()
{
	for(NodeI* n:children)
		delete n;
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
NodeI *GroupBeginNode::accept(NodeVisitor *v)
{
	return v->visit(this);
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

NonCapturingGroupBeginNode::NonCapturingGroupBeginNode()
{
}
StringIterator NonCapturingGroupBeginNode::in(StringIterator it)
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
NodeI *NonCapturingGroupBeginNode::accept(NodeVisitor *v)
{
	return v->visit(this);
}

LookAheadNode::LookAheadNode()
{
	next = new NonCapturingGroupBeginNode();
	next->setPred(this);
}
LookAheadNode::~LookAheadNode()
{
	delete next_in;
}
StringIterator LookAheadNode::in(StringIterator it)
{
	if(next->in(it).isValid(false))
	{
		return next_in->in(it);
	}
	return it;
}

NodeI *LookAheadNode::accept(NodeVisitor *v)
{
	return v->visit(this);
}
NodeI *LookAheadNode::getIntern()
{
	return next;
}
void LookAheadNode::setEnd(NodeI *n)
{
	groupLast = n;
}
void LookAheadNode::Valid()
{
	valider = new EndNode();
	groupLast->setNext(new EndNode());
}
NodeI* LookAheadNode::get()
{
	return next;
}
NodeI *LookAheadNode::link(NodeI *Next)
{
	return next_in = Next;
}
NegLookAheadNode::NegLookAheadNode() : LookAheadNode()
{

}
NodeI *NegLookAheadNode::accept(NodeVisitor *v)
{
	return v->visit(this);
}
StringIterator NegLookAheadNode::in(StringIterator it)
{
	StringIterator temp = it;
	if ( (next->in(it)).isValid())
	{
			return it;
	}
	else
	{
		return next_in->in(temp);
	}
	return it;
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

NodeI *BeginNode::accept(NodeVisitor *v)
{
	return v->visit(this);
}
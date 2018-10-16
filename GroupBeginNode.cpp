#include "GroupBeginNode.h"
#include "DecoratorVisitor.h"
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
NodeI* GroupBeginNode::accept(DecoratorVisitor* v)
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
	it.cleanLast();
	return it;
}
NodeI *NonCapturingGroupBeginNode::accept(DecoratorVisitor *v)
{
	return v->visit(this);
}

LookAheadNode::LookAheadNode()
{
	next = new NonCapturingGroupBeginNode();
	next->setPred(this);
}
StringIterator LookAheadNode::in(StringIterator it)
{
	if(next->in(it).isValid())
	{
		return next_in->in(it);
	}
	return it;
}
NodeI *LookAheadNode::accept(DecoratorVisitor *v)
{
	groupLast = groupLast->accept(v);
	groupLast->setNext(valider);
	return this;
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
	groupLast->setNext(valider);
}
NodeI* LookAheadNode::get()
{
	return next;
}
NodeI *LookAheadNode::link(NodeI *Next)
{
	return next_in = Next;
}
NegLookAheadNode::NegLookAheadNode()
{
	next = new NonCapturingGroupBeginNode();
	next->setPred(this);
}
StringIterator NegLookAheadNode::in(StringIterator it)
{
	if (!next->in(it).isValid())
	{
		return next_in->in(it);
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
NodeI *BeginNode::accept(DecoratorVisitor *v)
{
	return v->visit(this);
}
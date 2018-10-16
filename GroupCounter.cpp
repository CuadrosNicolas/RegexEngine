#include "GroupCounter.h"
#include "DecoratorVisitor.h"
BeginGroupCounter::BeginGroupCounter(EndGroupCounter *linkEnd, NodeI *sNext)
{
	endGrp = linkEnd;
	linkEnd->next = this;
	internNode = sNext;
}
void BeginGroupCounter::setMax(int ma)
{
	endGrp->max = ma;
}
void BeginGroupCounter::setMin(int mi)
{
	endGrp->min = mi;
}
EndGroupCounter *BeginGroupCounter::getEnd()
{
	return endGrp;
}
StringIterator BeginGroupCounter::sub_in(StringIterator it)
{
	StringIterator temp = it;
	if (endGrp->counter < endGrp->max || endGrp->max == -1)
	{
		temp = internNode->in(it);
		if (!temp.isValid())
		{
			return it;
		}
		else
		{
			return temp;
		}
	}
	return it;
}
StringIterator BeginGroupCounter::next_in(StringIterator it)
{
	if (endGrp->counter >= endGrp->min)
	{
		return next->in(it);
	}
	return it;
}
StringIterator BeginGroupCounter::in(StringIterator it)
{
	StringIterator temp;
	temp = sub_in(it);
	if(temp.isValid())
		return temp;
	return next_in(it);
}

EndGroupCounter::EndGroupCounter(int mi,int ma)
{
	min = mi;
	max = ma;
	counter = 0;
}

StringIterator EndGroupCounter::in(StringIterator it)
{
	counter++;
	StringIterator temp = next->in(it);
	if(!temp.isValid())
		counter--;
	return temp;
}
NodeI *BeginGroupCounter::accept(DecoratorVisitor* v)
{
	return v->visit(this);
}
GroupLazy::GroupLazy(BeginGroupCounter* begGrp)
{
	internGrp = begGrp;
	internGrp->getPred()->setNext(this);
	internGrp->getEnd()->setNext(this);
}
StringIterator GroupLazy::in(StringIterator it)
{
	StringIterator temp;
	temp = internGrp->next_in(it);
	if (temp.isValid())
		return temp;
	return internGrp->sub_in(it);

}

NodeI *GroupLazy::getPred()
{
	return internGrp->getPred();
}

NodeI *GroupLazy::link(NodeI *node)
{
	return internGrp->link(node);
}
#include "GroupCounter.h"
#include "DecoratorVisitor.h"
BeginGroupCounter::BeginGroupCounter(EndGroupCounter *linkEnd, NodeI *sNext)
{
	endGrp = linkEnd;
	linkEnd->bgGrp = this;
	subNext = sNext;
}
StringIterator BeginGroupCounter::sub_in(StringIterator it)
{
	StringIterator temp = it;
	if (endGrp->counter <= endGrp->max || endGrp->max == -1)
	{
		temp = subNext->in(it);
		if (!temp.isValid())
		{
			endGrp->counter--;
			it.cleanLast();
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
	return bgGrp->in(it);
}
NodeI *BeginGroupCounter::accept(DecoratorVisitor* v)
{
	return v->visit(this);
}
GroupLazy::GroupLazy(BeginGroupCounter* begGrp)
{
	internGrp = begGrp;
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
#include "GroupCounter.h"

BeginGroupCounter::BeginGroupCounter(EndGroupCounter *linkEnd, NodeI *sNext)
{
	endGrp = linkEnd;
	linkEnd->bgGrp = this;
	subNext = sNext;
}
StringIterator BeginGroupCounter::in(StringIterator it)
{
	StringIterator temp=it;
	if(endGrp->counter <= endGrp->max || endGrp->max == -1)
	{
		temp = subNext->in(it);
		if(!temp.isValid())
		{
			endGrp->counter--;
			it.cleanLast();
		}
		else
		{
			return temp;
		}
	}
	if(endGrp->counter >= endGrp->min)
	{
		return next->in(it);
	}
	return it;
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
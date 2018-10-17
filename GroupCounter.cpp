#include "GroupCounter.h"
#include "DecoratorVisitor.h"
BeginGroupCounter::BeginGroupCounter(EndGroupCounter *linkEnd, NodeI *sNext,int mi,int ma)
{
	//linkEnd->next = this;
	internNode = sNext;
	min = mi;
	max = ma;
	counter = 0;
}
void BeginGroupCounter::setMax(int ma)
{
	max = ma;
}
void BeginGroupCounter::setMin(int mi)
{
	min = mi;
}
void BeginGroupCounter::setEnd(NodeI* n)
{
	endGrp = n;
}
NodeI *BeginGroupCounter::getEnd()
{
	return endGrp;
}
StringIterator BeginGroupCounter::sub_in(StringIterator it)
{
	StringIterator temp = it;
	if (counter <= max || max == -1)
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
	if (counter >= min)
	{
		return next->in(it);
	}
	return it;
}
StringIterator BeginGroupCounter::in(StringIterator it)
{
	StringIterator temp;
	counter++;
	temp = sub_in(it);
	if(temp.isValid())
	{
		counter--;
		return temp;
	}
	else
		counter--;
	temp = next_in(it);
	return temp;
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
	else
	{
		internGrp->counter++;
		temp = internGrp->sub_in(it);
		if(temp.isValid())
		{
			internGrp->counter--;
			return temp;
		}
		else
		{
			internGrp->counter--;
			return it;
		}
	}
	return it;


}

NodeI *GroupLazy::getPred()
{
	return internGrp->getPred();
}

NodeI *GroupLazy::link(NodeI *node)
{
	return internGrp->link(node);
}
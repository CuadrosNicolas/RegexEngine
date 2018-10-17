#include "Counter.h"
#include "DecoratorVisitor.h"
Counter::Counter(NodeI *sNext, int mi, int ma)
{
	internNode = sNext;
	min = mi;
	max = ma;
	counter = 0;
}
void Counter::setMax(int ma)
{
	max = ma;
}
void Counter::setMin(int mi)
{
	min = mi;
}
void Counter::setEnd(NodeI *n)
{
	endGrp = n;
}
NodeI *Counter::getEnd()
{
	return endGrp;
}
StringIterator Counter::sub_in(StringIterator it)
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
StringIterator Counter::next_in(StringIterator it)
{
	if (counter >= min)
	{
		return next->in(it);
	}
	return it;
}
StringIterator Counter::in(StringIterator it)
{
	StringIterator temp;
	counter++;
	temp = sub_in(it);
	if (temp.isValid())
	{
		counter--;
		return temp;
	}
	else
		counter--;
	temp = next_in(it);
	return temp;
}
NodeI *Counter::accept(DecoratorVisitor *v)
{
	return v->visit(this);
}
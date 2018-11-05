#include "Counter.h"
#include "DecoratorVisitor.h"
Counter::Counter(NodeI *sNext, int mi, int ma)
{
	s_counter = new std::stack<int>();
	internNode = sNext;
	min = mi;
	max = ma;
	counter =0;
	s_counter->push(0);
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
		s_counter->push(counter);
		counter = 0;
		return next->in(it);
	}
	counter = s_counter->top();
	s_counter->pop();
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
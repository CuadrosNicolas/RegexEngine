#include "Counter.h"
#include "DecoratorVisitor.h"
Counter::Counter(NodeI* node)
{
	internNode = node;
	node->getPred()->setNext(this);
}
Counter::Counter(NodeI *node, int minimum, int maximum)
{
	min = minimum;
	max = maximum;
	internNode = node;
	node->getPred()->setNext(this);
}
void Counter::setMin(int i)
{
	min = i;
}
void Counter::setMax(int i)
{
	max = i;
}
NodeI* Counter::getPred()
{
	return internNode->getPred();
}
bool Counter::test(char c)
{
	return true;
}
StringIterator Counter::in(StringIterator it)
{
	return count(it,0);
}
StringIterator Counter::intern_in(StringIterator it,int actual)
{
	if (actual >= min)
	{
		return next->in(it);
	}
	return it;
}
bool Counter::intern_test(StringIterator it,int actual)
{
	if ((actual < max || max == -1))
	{
		return internNode->test(it.get());
	}
	return false;
}
StringIterator Counter::count(StringIterator it, int actual)
{
	StringIterator temp=it;

		if (it.end()==false && intern_test(it, actual)&&(temp = count(it + 1, actual + 1)).isValid())
			return temp;
		else
			return intern_in(it, actual);

	return it;
}
NodeI *Counter::accept(DecoratorVisitor *v){
	 return v->visit(this);
};
Counter *Counter::Star(NodeI *node)
{
	return new Counter(node,0,-1);
}
Counter *Counter::Plus(NodeI *node)
{
	return new Counter(node, 1, -1);
}
Counter *Counter::interrogation(NodeI *node)
{
	return new Counter(node, 0, 1);
}

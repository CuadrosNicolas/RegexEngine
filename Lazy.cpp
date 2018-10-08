#include "Lazy.h"

Lazy::Lazy(Counter *node)
{
	internNode = node;
	node->getPred()->setNext(this);
}
NodeI *Lazy::link(NodeI *node)
{
	return internNode->link(node);
}
bool Lazy::test(char c)
{
	return true;
}
StringIterator Lazy::count(StringIterator it, int actual)
{
	StringIterator temp;
	temp = internNode->intern_in(it, actual);
	if (temp.isValid())
		return temp;
	else if (internNode->intern_test(it, actual))
	{
		return count(it + 1, actual + 1);
	}

	return it;
}
NodeI *Lazy::getPred()
{
	return internNode->getPred();
}
StringIterator Lazy::in(StringIterator it)
{
	return count(it,0);
}
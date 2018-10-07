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
	bool temp_count;
	if (!it.end())
	{
		temp = internNode->intern_in(it, actual);
		if (temp.isValid())
			return temp;
		else
		{
			temp_count = internNode->intern_test(it, actual);
			if (temp_count)
				return count(it + 1, actual + 1);
		}
	}
	else
	{
		return it;
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
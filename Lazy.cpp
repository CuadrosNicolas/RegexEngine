#include "Lazy.h"
#include "Counter.h"
#include "NodeVisitor.h"
Lazy::Lazy(Counter *begGrp)
{
	internGrp = begGrp;
	internGrp->getPred()->setNext(this);
	internGrp->getEnd()->setNext(this);
}
Lazy::~Lazy()
{
	delete internGrp;
}
StringIterator Lazy::in(StringIterator it)
{

	StringIterator temp;
	temp = internGrp->next_in(it);
	if (temp.isValid())
		return temp;
	else
	{
		internGrp->counter++;
		temp = internGrp->sub_in(it);
		if (temp.isValid())
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

NodeI *Lazy::getPred()
{
	return internGrp->getPred();
}

NodeI *Lazy::link(NodeI *node)
{
	return internGrp->link(node);
}
NodeI *Lazy::accept(NodeVisitor *v)
{
	return v->visit(this);
}
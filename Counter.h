#pragma once
#include "NodeI.h"
#include "DecoratorNode.h"
#include "Lazy.h"


class Counter : public DecoratorNode
{
	friend class Lazy;

  public:
	Counter(NodeI *sNext, int mi, int ma);
	StringIterator sub_in(StringIterator it);
	StringIterator next_in(StringIterator it);
	StringIterator in(StringIterator it);
	NodeI *accept(DecoratorVisitor *v);
	NodeI *getEnd();
	void setMin(int mi);
	void setMax(int ma);
	void setEnd(NodeI *n);

  protected:
	NodeI *endGrp;
	int min;
	int max;
	int counter;
};
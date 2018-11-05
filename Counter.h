#pragma once
#include <stack>
#include "NodeI.h"
#include "DecoratorNode.h"
#include "Lazy.h"

/**
 * @brief
 * Node which need to match a minimum/maximum number of intern node to go
 * to her next node (quantifier)
 */
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
	std::stack<int>* s_counter;
};
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
	friend class NodeCopier;
	Counter(int mi, int ma);
	Counter(NodeI *sNext, int mi, int ma);
	~Counter();
	StringIterator sub_in(StringIterator it);
	StringIterator next_in(StringIterator it);
	StringIterator in(StringIterator it);
	NodeI *accept(NodeVisitor *v);
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
#pragma once
#include "NodeI.h"
#include "DecoratorNode.h"
class EndGroupCounter;
class BeginGroupCounter : public DecoratorNode
{
	friend class EndGroupCounter;
	friend class GroupLazy;

  public:
	BeginGroupCounter(EndGroupCounter* linkEnd,NodeI* sNext,int mi,int ma);
	StringIterator sub_in(StringIterator it);
	StringIterator next_in(StringIterator it);
	StringIterator in(StringIterator it);
	NodeI *accept(DecoratorVisitor *v);
	NodeI* getEnd();
	void setMin(int mi);
	void setMax(int ma);
	void setEnd(NodeI* n);
  protected:
	NodeI *endGrp;
	int min;
	int max;
	int counter;

};

class EndGroupCounter : public NodeI
{
	friend class BeginGroupCounter;
	public:
	EndGroupCounter(int mi,int ma);
	StringIterator in(StringIterator it);


  protected:
	int counter;
	int min;
	int max;
};

class GroupLazy : public DecoratorNode
{
	public:
		GroupLazy(BeginGroupCounter *begGrp);
		StringIterator in(StringIterator it);
		NodeI *link(NodeI *node);
		NodeI *getPred();

  protected:
	BeginGroupCounter *internGrp;
};

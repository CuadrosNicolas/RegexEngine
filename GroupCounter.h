#pragma once
#include "NodeI.h"
#include "DecoratorNode.h"
class EndGroupCounter;
class BeginGroupCounter : public DecoratorNode
{
	friend class EndGroupCounter;
	public:
	BeginGroupCounter(EndGroupCounter* linkEnd,NodeI* sNext);
	StringIterator sub_in(StringIterator it);
	StringIterator next_in(StringIterator it);
	StringIterator in(StringIterator it);
	NodeI *accept(DecoratorVisitor *v);
	EndGroupCounter* getEnd();
	void setMin(int mi);
	void setMax(int ma);
  protected:
	EndGroupCounter *endGrp;


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
		GroupLazy(BeginGroupCounter* begGrp);
		StringIterator in(StringIterator it);
		NodeI* link(NodeI* node);
		NodeI* getPred();
	protected:
		BeginGroupCounter* internGrp;
};

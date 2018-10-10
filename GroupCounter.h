#pragma once
#include "NodeI.h"
class EndGroupCounter;
class BeginGroupCounter : public NodeI
{
	friend class EndGroupCounter;
	public:
	BeginGroupCounter(EndGroupCounter* linkEnd,NodeI* sNext);
	StringIterator sub_in(StringIterator it);
	StringIterator next_in(StringIterator it);
	StringIterator in(StringIterator it);
	NodeI *accept(DecoratorVisitor *v);

  protected:
	EndGroupCounter *endGrp;
	NodeI *subNext;

};

class EndGroupCounter : public NodeI
{
	friend class BeginGroupCounter;
	public:
	EndGroupCounter(int mi,int ma);
	StringIterator in(StringIterator it);


  protected:
	BeginGroupCounter* bgGrp;
	int counter;
	int min;
	int max;
};

class GroupLazy : public NodeI
{
	public:
		GroupLazy(BeginGroupCounter* begGrp);
		StringIterator in(StringIterator it);
		NodeI* link(NodeI* node);
		NodeI* getPred();
	protected:
		BeginGroupCounter* internGrp;
};

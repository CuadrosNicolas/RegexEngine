#pragma once
#include "NodeI.h"
class EndGroupCounter;

class BeginGroupCounter : public NodeI
{
	friend class EndGroupCounter;
	public:
	BeginGroupCounter(EndGroupCounter* linkEnd,NodeI* sNext);
	StringIterator in(StringIterator it);

	protected:
		EndGroupCounter* endGrp;
		NodeI* subNext;

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

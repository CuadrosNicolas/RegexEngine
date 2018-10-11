#pragma once
#include "NodeI.h"

class DecoratorNode : public NodeI
{
	public:
		virtual void setMin(int mi){
			min = mi;
		};
		virtual void setMax(int ma)
		{
			max = ma;
		};
	protected:
		NodeI* internNode=nullptr;
		int min=0;
		int max=0;
};
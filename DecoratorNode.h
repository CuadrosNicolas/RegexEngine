#pragma once
#include "NodeI.h"

class DecoratorNode : public NodeI
{
	protected:
		NodeI* internNode=nullptr;
};
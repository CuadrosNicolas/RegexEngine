#pragma once
#include "NodeI.h"

class BeginNode : public NodeI
{
  public:
	BeginNode();
	bool test(char c);
	StringIterator in(StringIterator it);
};

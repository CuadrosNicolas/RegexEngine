#pragma once
#include "NodeI.h"

class EndNode : public NodeI
{
  public:
		EndNode();
		bool test(char c);
		StringIterator in(StringIterator it);
};
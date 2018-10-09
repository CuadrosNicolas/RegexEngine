#pragma once
#include "Counter.h"
class Lazy : public DecoratorNode
{
	public:
		Lazy(Counter* node);
		bool test(char c);
		StringIterator count(StringIterator it,int actual);
		StringIterator in(StringIterator it);
		NodeI* link(NodeI* node);
		NodeI *getPred();
	  private:
		Counter* internNode;
};
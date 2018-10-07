#pragma once
#include "Counter.h"
class Lazy : public NodeI
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
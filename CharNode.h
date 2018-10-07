#pragma once
#include "NodeI.h"
#include <iostream>
class CharNode : public NodeI
{
	public:
		CharNode(char c);
		bool test(char c);
		StringIterator in(StringIterator it);
		void setPred(NodeI *n);
		void setNext(NodeI *n);

	  private:
		char value;
};
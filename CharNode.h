#pragma once
#include "NodeI.h"
#include "RegFlags.h"
#include "CharFunction.h"
#include <iostream>
class CharNode : public NodeI
{
	public:
		CharNode(char c);
		virtual bool test(char c);
		StringIterator in(StringIterator it);
		void setPred(NodeI *n);
		void setNext(NodeI *n);

	  protected:
		char value;
};

class CharNodeInsensitive : public CharNode
{
public:
	CharNodeInsensitive(char c);
	bool test(char c);
};

NodeI* getCharNode(char c,int F);
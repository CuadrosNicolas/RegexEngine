#pragma once
#include "NodeI.h"
#include "CharFunction.h"
#include "RegFlags.h"
#include <vector>
class SetNode : public NodeI
{
	public:
		SetNode();
		virtual bool test(char c);
		StringIterator in(StringIterator it);
		void setPred(NodeI *n);
		void setNext(NodeI*n);
		void addChar(char c);
		void addSet(char a,char b);
		void setNot();
	protected:
		std::vector<char> charList;
		std::vector<char*> setList;
		bool isNot;
};

class SetNodeInsensitive : public SetNode
{
	public:
		SetNodeInsensitive();
		bool test(char c);
};

SetNode* getSetNode(int f);
#pragma once
#include "NodeI.h"
#include <vector>
class SetNode : public NodeI
{
	public:
		SetNode();
		bool test(char c);
		StringIterator in(StringIterator it);
		void setPred(NodeI *n);
		void setNext(NodeI*n);
		void addChar(char c);
		void addSet(char a,char b);
		void setNot();
	private:
		std::vector<char> charList;
		std::vector<char*> setList;
		bool isNot;
};
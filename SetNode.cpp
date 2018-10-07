#include "SetNode.h"

SetNode::SetNode()
{
	isNot=false;
}
bool SetNode::test(char c)
{
	bool out=false;
	for(char i : charList)
	{
		if(c==i)
		{
			out=true;
			break;
		}
	}
	if(!out)
	{
		for(char* i : setList)
		{
			if(c>=(*i) && c<=*(i+1))
			{
				out=true;
				break;
			}
		}
	}
	return out^isNot;
}
StringIterator SetNode::in(StringIterator it)
{
	if (!it.end())
	{
		if (this->test(it.get()))
		{
			return this->next->in(it + 1);
		}
	}
	return it;
}
void SetNode::setPred(NodeI *n)
{
	pred = n;
}
void SetNode::setNext(NodeI *n)
{
	next = n;
}
void SetNode::addChar(char c)
{
	charList.push_back(c);
}
void SetNode::addSet(char a, char b)
{
	char* ch = new char[2];
	ch[0] = a;
	ch[1] = b;
	setList.push_back(ch);
}
void SetNode::setNot()
{
	isNot = true;
}
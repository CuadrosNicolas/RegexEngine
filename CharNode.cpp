#include "CharNode.h"

CharNode::CharNode(char c)
{
	value = c;
}
bool CharNode::test(char c)
{
	return c == value;
}
StringIterator CharNode::in(StringIterator it)
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
void CharNode::setPred(NodeI *n) { pred = n; }
void CharNode::setNext(NodeI *n) { next = n; }

CharNodeInsensitive::CharNodeInsensitive(char c) : CharNode(c)
{

}
bool CharNodeInsensitive::test(char c)
{
	if(LowerCase(value))
	{
		return value==c || ToUpper(value)==c;
	}
	else{
		return value == c || ToLower(value) == c;
	}
}

NodeI* getCharNode(char c,int F)
{
	if ( (F & CASE_INSENSITIVE) && Letter(c))
	{
			return new CharNodeInsensitive(c);
	}
	return new CharNode(c);
}
#include "StrNode.h"
#include "NodeVisitor.h"
StrNode::StrNode(std::string v)
{
	value = v;
}

bool StrNode::test(char c)
{
	return true;
}
StringIterator StrNode::in(StringIterator it)
{
	if (!it.end())
	{
		StringIterator temp = it;
		for(char c : value)
		{
			if(c != temp.get())
			{
				return it;
			}
			temp = temp +1;
		}
		return this->next->in(temp);
	}
	return it;
}
NodeI *StrNode::accept(NodeVisitor *v)
{
	return v->visit(this);
}

StrNodeInsensitive::StrNodeInsensitive(std::string v)
{
	value = v;
}

bool StrNodeInsensitive::test(char c)
{
	return true;
}
bool StrNodeInsensitive::testValue(char in, char c)
{
	if (LowerCase(in))
	{
		return in == c || ToUpper(in) == c;
	}
	else
	{
		return in == c || ToLower(in) == c;
	}
}
StringIterator StrNodeInsensitive::in(StringIterator it)
{
	if (!it.end())
	{
		StringIterator temp = it;
		for (char c : value)
		{
			if (!testValue(c,temp.get()))
			{
				return it;
			}
			temp = temp + 1;
		}
		return this->next->in(temp);
	}
	return it;
}
NodeI *StrNodeInsensitive::accept(NodeVisitor *v)
{
	return v->visit(this);
}

NodeI *getStrNode(std::string c, int F)
{
	if ((F & CASE_INSENSITIVE))
	{
		return new StrNodeInsensitive(c);
	}
	return new StrNode(c);
}
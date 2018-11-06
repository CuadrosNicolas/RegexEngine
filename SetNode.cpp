#include "SetNode.h"
#include "NodeVisitor.h"
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
NodeI *SetNode::accept(NodeVisitor *v)
{
	return v->visit(this);
}
SetNodeInsensitive::SetNodeInsensitive()
{
}
NodeI *SetNodeInsensitive::accept(NodeVisitor *v)
{
	return v->visit(this);
}
bool SetNodeInsensitive::test(char c)
{
	bool out = false;
	for (char i : charList)
	{
		if (c == i)
		{
			out = true;
			break;
		}
		else if(Letter(i))
		{
			if(upperCase(i))
			{
				if(c==ToUpper(i))
				{
					out = true;
					break;
				}
			}
			else
			{
				if(c==ToLower(i))
				{
					out = true;
					break;
				}
			}
		}
	}
	if (!out)
	{
		for (char *i : setList)
		{
			if(Letter(c))
			{
				if(upperCase(c))
				{
					char temp = ToLower(c);
					if(temp >= (*i) && temp <=*(i+1))
					{
						out = true;
						break;
					}
				}else
				{
					char temp = ToUpper(c);
					if (temp >= (*i) && temp <= *(i + 1))
					{
						out = true;
						break;
					}
				}
			}
			if (c >= (*i) && c <= *(i + 1))
			{
				out = true;
				break;
			}
		}
	}
	return out ^ isNot;
}

SetNode *getSetNode(int f)
{
	if(f & CASE_INSENSITIVE)
	{
		return new SetNodeInsensitive();
	}
	return new SetNode();
}
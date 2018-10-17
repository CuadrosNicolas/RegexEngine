#include "AnchorNode.h"

AnchorBeginNode::AnchorBeginNode()
{

}
StringIterator AnchorBeginNode::in(StringIterator it)
{
	if((it-1).end())
	{
		return this->next->in(it);
	}
	return it;
}

AnchorEndNode::AnchorEndNode()
{

}
StringIterator AnchorEndNode::in(StringIterator it)
{
	if ((it).end())
	{
		return this->next->in(it);
	}
	return it;
}
AnchorMultiLineLeft::AnchorMultiLineLeft()
{

}
bool AnchorMultiLineLeft::test(char c)
{
	return c=='\n';
}
StringIterator AnchorMultiLineLeft::in(StringIterator it)
{
	if (test((it-1).get())  || (it-1).end() == true)
	{
		return next->in(it);
	}
	return it;
}
AnchorMultiLineRight::AnchorMultiLineRight()
{

}
bool AnchorMultiLineRight::test(char c)
{
	return c == '\n';
}
StringIterator AnchorMultiLineRight::in(StringIterator it)
{
	if (test(it.get()) || (it).end() == true)
	{
		return next->in(it+1);
	}
	return it;
}
AnchorWordBoundariesNode::AnchorWordBoundariesNode()
{

}

bool AnchorWordBoundariesNode::leftBoundaries(StringIterator it) const
{
	if (!it.end())
	{
		return !Word(it.get());
	}
	return true;
}
bool AnchorWordBoundariesNode::rightBoundaries(StringIterator it) const
{
	if (!it.end())
	{
		return Word(it.get());
	}
	return false;
}
StringIterator AnchorWordBoundariesNode::in(StringIterator it)
{
	if(!it.end())
	{
		if (Word(it.get()))
		{
			if (leftBoundaries(it-1))
			{
				return next->in(it);
			}
		}
		else
		{
			if(rightBoundaries(it-1))
			{
				return next->in(it+1);
			}
		}
	}
	else
	{
		if (rightBoundaries(it - 1))
		{
			return next->in(it+1);
		}
	}
	return it;
}

AnchorNotWordBoundariesNode::AnchorNotWordBoundariesNode()
{

}
StringIterator AnchorNotWordBoundariesNode::in(StringIterator it)
{
	if (!it.end())
	{
		if (Word(it.get()))
		{
			if (leftBoundaries(it - 1))
			{
				return it;
			}
		}
		else
		{
			if (rightBoundaries(it - 1))
			{
				return it;
			}
		}
	}
	else
	{
		if (rightBoundaries(it - 1))
		{
			return it;
		}
	}
	return next->in(it);
}

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

bool wordTest(char c){
	return (c >= 'A' && c <= 'Z') ||
		   (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '_';
}

AnchorWordBoundariesNode::AnchorWordBoundariesNode()
{

}

bool AnchorWordBoundariesNode::leftBoundaries(StringIterator it)
{
	if (!it.end())
	{
		return !wordTest(it.get());
	}
	return true;
}
bool AnchorWordBoundariesNode::rightBoundaries(StringIterator it)
{
	if (!it.end())
	{
		return wordTest(it.get());
	}
	return false;
}
StringIterator AnchorWordBoundariesNode::in(StringIterator it)
{
	if(!it.end())
	{
		if(wordTest(it.get()))
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
				return next->in(it);
			}
		}
	}
	else
	{
		if (rightBoundaries(it - 1))
		{
			return next->in(it);
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
		if (wordTest(it.get()))
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

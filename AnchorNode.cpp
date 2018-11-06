#include "AnchorNode.h"
#include "NodeVisitor.h"
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

NodeI *AnchorBeginNode::accept(NodeVisitor *v)
{
	return v->visit(this);
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
NodeI *AnchorEndNode::accept(NodeVisitor *v)
{
	return v->visit(this);
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
NodeI *AnchorMultiLineLeft::accept(NodeVisitor *v)
{
	return v->visit(this);
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
NodeI *AnchorMultiLineRight::accept(NodeVisitor *v)
{
	return v->visit(this);
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
NodeI *AnchorWordBoundariesNode::accept(NodeVisitor *v)
{
	return v->visit(this);
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
NodeI *AnchorNotWordBoundariesNode::accept(NodeVisitor *v)
{
	return v->visit(this);
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

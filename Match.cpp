#include "Match.h"

Match::Match()
{
	begin = 0;
	end = 0;
	parent = nullptr;
	value = "";
}
Match::Match(Match* par)
{
	begin = 0;
	end = 0;
	parent = par;
	value = "";
}
void Match::setBegin(size_t i)
{
	begin = i;
}
void Match::setEnd(size_t i)
{
	end = i;
}
Match* Match::getParent()
{
	return parent;
}
Match* Match::addChild()
{
	Match* temp = new Match(parent);
	parent->childs.push_back(temp);
	return temp;
}
Match* Match::push()
{
	Match* temp = new Match(this);
	childs.push_back(temp);
	return temp;
}
Match::~Match()
{
	for(Match* c : childs)
	{
		delete c;
	}
}
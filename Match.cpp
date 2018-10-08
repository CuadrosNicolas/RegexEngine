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
Match::Match(const Match& m)
{
	begin = m.begin;
	end = m.end;
	value = m.value;
	parent = m.parent;
	for(Match* child : m.childs)
	{
		childs.push_back(new Match(*child));
	}
}
Match::Match(const Match *m)
{
	begin = m->begin;
	end = m->end;
	value = m->value;
	parent = m->parent;
	for (Match *child : m->childs)
	{
		childs.push_back(new Match(*child));
	}
}
void Match::setBegin(size_t i)
{
	begin = i;
}
void Match::setEnd(size_t i)
{
	if(parent!=nullptr)
	{
		end = i;
		parent->setEnd(i);
	}
}
std::string Match::getValue()
{
	return value;
}
size_t Match::getBegin()
{
	return begin;
}
size_t Match::getEnd()
{
	return end;
}
Match* Match::getParent()
{
	if(parent!=nullptr)
	return parent;
	else
	return this;
}
std::vector<Match*> Match::getChild()
{
	return childs;
}
Match* Match::addChild()
{
	if(parent!=nullptr)
	{
		Match* temp = new Match(parent);
		parent->childs.push_back(temp);
		return temp;
	}
	else
	{
		Match *temp = new Match(this);
		childs.push_back(temp);
		return temp;
	}
}
Match* Match::push()
{
	Match* temp = new Match(this);
	childs.push_back(temp);
	return temp;
}
void Match::popLast()
{
	childs.pop_back();
}
std::string Match::getPrint()
{
	return getPrint(-1);
}
std::string Match::getPrint(int i)
{
	std::string s="";
	if(value!= "")
	{
		for(int j = 0;j<i;j++)
		{
			s += "\t";
		}
		s += value + "\n";
	}
	if(childs.size()==0)
	{
		return s;
	}
	else
	{
		for(Match* m : childs)
		{
			s += m->getPrint(i+1);
		}
		return s;
	}
}
void Match::setValue(std::string* source)
{
	value = source->substr(begin,end-begin);
	for(Match* m : childs)
	{
		m->setValue(source);
	}
}
Match::~Match()
{
	for(Match* c : childs)
	{
		delete c;
	}
}
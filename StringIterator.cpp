#include "StringIterator.h"
StringIterator::StringIterator()
{
	value = "";
	source = nullptr;
	pos = 0;
	valid = false;
	lastPos = 0;
	matchs = new Match();
	outMatchs = matchs;
}
StringIterator::StringIterator(std::string *s)
{
	source = s;
	pos = 0;
	valid = false;
	lastPos = 0;
	matchs = new Match();
	outMatchs = matchs;
}
StringIterator::StringIterator(const StringIterator& it)
{
	source = it.source;
	pos = it.pos;
	valid = it.valid;
	lastPos = it.lastPos;
	value = it.value;
	matchs = it.matchs;
	outMatchs = it.outMatchs;
}
void StringIterator::init()
{
	matchs = outMatchs->addChild();
}
StringIterator StringIterator::operator=(const StringIterator& it)
{
	source = it.source;
	pos = it.pos;
	valid = it.valid;
	lastPos = it.lastPos;
	value = it.value;
	matchs = it.matchs;
	outMatchs = it.outMatchs;
	return *this;
}
bool StringIterator::isValid()
{
	return valid && value!="";
}
StringIterator StringIterator::validPos()
{
	StringIterator temp(*this);
 	temp.value = (*source).substr(lastPos, pos - lastPos);
	temp.valid = true;
	temp.matchs->setValue(source);
	return temp;
}
void StringIterator::reinit()
{
	lastPos = pos;
	if(valid)
	{

		matchs = outMatchs->addChild();
		matchs->setBegin(pos);
	}
	else
	{
		matchs->popLast();
	}
	valid = false;
}
char StringIterator::get()
{
	return (*source)[pos];
}
bool StringIterator::end()
{
	return pos<0 ||pos>=source->size();
}
void StringIterator::clean()
{
	outMatchs->popLast();
}
void StringIterator::cleanLast()
{
	matchs->popLast();
}
Match* StringIterator::getMatch()
{
	return outMatchs;
}
std::string StringIterator::getValue()
{
	return value;
}
Match* StringIterator::addChild()
{
	return matchs = matchs->addChild();
}
void StringIterator::backMatch()
{
	if(matchs->getParent()!=nullptr)
		matchs = matchs->getParent();
}
Match* StringIterator::push()
{
	return matchs = matchs->push(pos);
}
Match* StringIterator::antiPush()
{
	return matchs = matchs->antiPush();
}
StringIterator operator-(const StringIterator &it, int i)
{
	StringIterator temp(it);
	temp.pos = it.pos - i;
	temp.matchs->setEnd(temp.pos);
	return temp;
}
StringIterator operator+(const StringIterator& it,int i)
{
	StringIterator temp(it);
	temp.pos = it.pos+i;
	temp.matchs->setEnd(temp.pos);
	return temp;
}
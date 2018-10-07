#include "StringIterator.h"
StringIterator::StringIterator()
{
	value = "";
	source = nullptr;
	pos = 0;
	valid = false;
	lastPos = 0;
}
StringIterator::StringIterator(std::string *s)
{
	source = s;
	pos = 0;
	valid = false;
	lastPos = 0;
}
StringIterator::StringIterator(const StringIterator& it)
{
	source = it.source;
	pos = it.pos;
	valid = it.valid;
	lastPos = it.lastPos;
	value = it.value;
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
	return temp;
}
void StringIterator::reinit()
{
	lastPos = pos;
	valid = false;
}
char StringIterator::get()
{
	return (*source)[pos];
}
bool StringIterator::end()
{
	return pos>=source->size();
}
std::string StringIterator::getValue()
{
	return value;
}
StringIterator operator+(const StringIterator& it,int i)
{
	StringIterator temp(it);
	temp.pos = it.pos+i;
	return temp;
}
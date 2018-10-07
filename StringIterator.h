#pragma once
#include <string>
class StringIterator
{
  public:
	StringIterator();
	StringIterator(std::string *s);
	StringIterator(const StringIterator& s);
	char get();
	bool end();
	StringIterator validPos();
	bool isValid();
	void reinit();
	std::string getValue();
	std::string *source;
	size_t pos;
	int lastPos;

private:
	std::string value;
	bool valid;
};
StringIterator operator+(const StringIterator& it,int i);
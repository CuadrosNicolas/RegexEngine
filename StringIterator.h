#pragma once
#include <string>
#include "Match.h"
class StringIterator
{
  public:
	StringIterator();
	StringIterator(std::string *s);
	StringIterator(const StringIterator& s);
	StringIterator operator=(const StringIterator& it);
	void init();
	char get();
	bool end();
	StringIterator validPos();
	bool isValid();
	void reinit();
	std::string getValue();
	std::string *source;
	size_t pos;
	int lastPos;
	void clean();
	void cleanLast();
	Match* getMatch();
	Match* addChild();
	Match* push();
	void backMatch();
	friend StringIterator operator-(const StringIterator &it, int i);
	friend StringIterator operator+(const StringIterator& it,int i);

private:
	Match* matchs;
	Match* outMatchs;
	std::string value;
	bool valid;

};

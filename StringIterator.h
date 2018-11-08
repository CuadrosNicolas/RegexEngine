#pragma once
#include <string>
#include "Match.h"
/**
 * @brief
 * Class use to iteratre through a string and store matches.
 */
class StringIterator
{
  public:
	StringIterator();
	StringIterator(std::string s);
	StringIterator(const StringIterator& s);
	StringIterator operator=(const StringIterator& it);
	void init();
	char get();
	bool end();
	StringIterator validPos();
	bool isValid(bool testContent=true);
	bool unvalid();
	void reinit();
	std::string getValue();
	std::string *source;
	std::string _source;
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

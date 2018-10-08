#pragma once
#include <string>
#include <vector>
class Match
{
	public:
		Match();
		Match(const Match& m);
		Match(const Match* m);
		Match(Match* par);
		~Match();
		Match* getParent();
		Match* addChild();
		Match* push();
		void setEnd(size_t i);
		void setBegin(size_t i);
		std::string getPrint();
		std::string getValue();
		size_t getBegin();
		size_t getEnd();
		std::vector<Match*> getChild();
		void setValue(std::string* source);
	private:
	  std::string getPrint(int actual);
	  size_t begin;
	  size_t end;
	  std::string value;
	  Match *parent;
	  std::vector<Match *> childs;

};
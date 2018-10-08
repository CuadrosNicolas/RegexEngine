#pragma once
#include <string>
#include <vector>
class Match
{
	public:
		Match();
		Match(Match* par);
		~Match();
		Match* getParent();
		Match* addChild();
		Match* push();
		void setEnd(size_t i);
		void setBegin(size_t i);
	private:
		size_t begin;
		size_t end;
		std::string value;
		Match* parent;
		std::vector<Match*> childs;

};
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
		virtual Match &operator=(const Match &m);
		virtual Match& operator=(const Match&& m);
		virtual ~Match();
		Match* getParent();
		Match* addChild();
		Match* push();
		Match *push(int pos);
		void setEnd(size_t i);
		void setBegin(size_t i);
		std::string getPrint() const;
		std::string getValue() const;
		size_t getBegin() const;
		size_t getEnd() const;
		std::vector<Match*> getChild() const;
		void setValue(std::string* source);
		void popLast();
	private:
	  std::string getPrint(int actual) const;
	  size_t begin;
	  size_t end;
	  std::string value;
	  Match *parent;
	  std::vector<Match *> childs;

};
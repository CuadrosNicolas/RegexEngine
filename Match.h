#pragma once
#include <string>
#include <vector>

class NodeI;
class StringIterator;
/**
 * @brief
 * Class use to store matches of a regex as a tree.
 * 
 */
class Match
{
	friend class NodeI;
	friend class StringIterator;
	public:
		virtual Match &operator=(const Match &m);
		virtual Match& operator=(const Match&& m);
		Match();
		Match(const Match& m);
		Match(const Match* m);
		Match(Match* par);
		virtual ~Match();
		std::string getPrint() const;
		std::string getValue() const;
		std::vector<Match*> getChild() const;

		friend StringIterator operator-(const StringIterator &it, int i);
		friend StringIterator operator+(const StringIterator &it, int i);

	  protected:
		Match* getParent();
		Match* addChild();
		Match* push();
		Match *push(int pos);
		void setEnd(size_t i);
		void setBegin(size_t i);
		size_t getBegin() const;
		size_t getEnd() const;
		void setValue(std::string* source);
		void popLast();
		std::string getPrint(int actual) const;
		size_t begin;
		size_t end;
		std::string value;
		Match *parent;
		std::vector<Match *> childs;

};
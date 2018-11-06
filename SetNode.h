#pragma once
#include "NodeI.h"
#include "CharFunction.h"
#include "RegFlags.h"
#include <vector>
/**
 * @brief
 * Node which will match a set of different character
 */
class SetNode : public NodeI
{
	public:
		friend class NodeCopier;
		SetNode();
		virtual bool test(char c);
		StringIterator in(StringIterator it);
		void setPred(NodeI *n);
		void setNext(NodeI*n);
		void addChar(char c);
		void addSet(char a,char b);
		void setNot();
		virtual NodeI *accept(NodeVisitor *v);

	  protected:
		std::vector<char> charList;
		std::vector<char*> setList;
		bool isNot;
};
/**
 * @brief
 * Node which will match a set of different character without paying attention to the case of the character.
 */
class SetNodeInsensitive : public SetNode
{
	public:
	  friend class NodeCopier;
	  SetNodeInsensitive();
	  virtual NodeI *accept(NodeVisitor *v);
	  bool test(char c);
};

SetNode* getSetNode(int f);
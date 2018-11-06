#pragma once
#include "NodeI.h"
#include "RegFlags.h"
#include "CharFunction.h"
#include <iostream>
/**
 * @brief
 *Basic node which match a character
 */
class CharNode : public NodeI
{
	public:
	  friend class NodeCopier;
	  CharNode(char c);
	  virtual bool test(char c);
	  StringIterator in(StringIterator it);
	  void setPred(NodeI *n);
	  void setNext(NodeI *n);
	  virtual NodeI *accept(NodeVisitor *v);

	protected:
	  char value;
};
/**
 * @brief
 * Basic node matching a character (in lower or upper case)
 */
class CharNodeInsensitive : public CharNode
{
public:
  friend class NodeCopier;
  CharNodeInsensitive(char c);
  bool test(char c);
  virtual NodeI *accept(NodeVisitor *v);
};
/**
 * @brief Get a char node object matching a character c in insensitive or sensitive mode
 *depending of the mode F.
 * @param c character to match
 * @param F mode of the builder
 * @return NodeI* CharNode
 */
NodeI* getCharNode(char c,int F);
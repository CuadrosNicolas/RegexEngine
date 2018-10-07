#pragma once
#include "DecoratorNode.h"

class Counter : public DecoratorNode
{
	public:
	  Counter(NodeI *node);
	  Counter(NodeI *node, int minimum, int maximum);
	  bool test(char c);
	  void setMin(int i);
	  void setMax(int i);
	  StringIterator count(StringIterator it, int actual);
	  StringIterator in(StringIterator it);
	  StringIterator intern_in(StringIterator it, int actual);
	  bool intern_test(StringIterator it, int actual);
	  NodeI *getPred();
	  NodeI *accept(DecoratorVisitor *v);
	  static Counter *Star(NodeI *node);
	  static Counter *Plus(NodeI *node);
	  static Counter *interrogation(NodeI *node);

	private:
	  int min;
	  int max;
};
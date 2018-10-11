#pragma once
#include "NodeI.h"
#include "CharFunction.h"
class AnchorBeginNode : public NodeI
{
	public:
		AnchorBeginNode();
		StringIterator in(StringIterator it);
};

class AnchorEndNode : public NodeI
{
	public:
		AnchorEndNode();
		StringIterator in(StringIterator it);
};

class AnchorMultiLineLeft : public NodeI
{
	public:
	  AnchorMultiLineLeft();
	  bool test(char c);
	  StringIterator in(StringIterator it);
};
class AnchorMultiLineRight : public NodeI
{
  public:
	AnchorMultiLineRight();
	bool test(char c);
	StringIterator in(StringIterator it);
};
class AnchorWordBoundariesNode : public NodeI
{
	public:
		AnchorWordBoundariesNode();
		virtual StringIterator in(StringIterator it);
		bool leftBoundaries(StringIterator it);
		bool rightBoundaries(StringIterator it);
};

class AnchorNotWordBoundariesNode : public AnchorWordBoundariesNode
{
	public:
	  AnchorNotWordBoundariesNode();
	  StringIterator in(StringIterator it);
};
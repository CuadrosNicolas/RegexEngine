#pragma once
#include "NodeI.h"
#include "CharFunction.h"
/**
 * @brief
 * Node to match begin of string
 */
class AnchorBeginNode : public NodeI
{
	public:
		AnchorBeginNode();
		StringIterator in(StringIterator it);
		virtual NodeI *accept(NodeVisitor *v);
};
/**
 * @brief
 * Node to match end of string
 */
class AnchorEndNode : public NodeI
{
	public:
		AnchorEndNode();
		StringIterator in(StringIterator it);
		virtual NodeI *accept(NodeVisitor *v);
};
/**
 * @brief
 * Node to match begin of line(line break at left)
 */
class AnchorMultiLineLeft : public NodeI
{
	public:
	  AnchorMultiLineLeft();
	  bool test(char c);
	  StringIterator in(StringIterator it);
	  virtual NodeI *accept(NodeVisitor *v);
};
/**
 * @brief
 * Node to match begin of line(line break at right)
 */
class AnchorMultiLineRight : public NodeI
{
  public:
	AnchorMultiLineRight();
	bool test(char c);
	StringIterator in(StringIterator it);
	virtual NodeI *accept(NodeVisitor *v);
};
/**
 * @brief
 * Node to match word boundaries
 */
class AnchorWordBoundariesNode : public NodeI
{
	public:
		AnchorWordBoundariesNode();
		virtual StringIterator in(StringIterator it);
		bool leftBoundaries(StringIterator it) const;
		bool rightBoundaries(StringIterator it) const;
		virtual NodeI *accept(NodeVisitor *v);
};
/**
 * @brief
 * Node which doesn't match word boundaries
 */
class AnchorNotWordBoundariesNode : public AnchorWordBoundariesNode
{
	public:
	  AnchorNotWordBoundariesNode();
	  StringIterator in(StringIterator it);
	  virtual NodeI *accept(NodeVisitor *v);
};
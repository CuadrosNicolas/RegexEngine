#pragma once
#include "NodeI.h"
#include "CharFunction.h"
class WordNode : public NodeI
{
  public:
	bool test(char c);
};
class NotWordNode : public NodeI
{
  public:
	bool test(char c);
};
class NumberNode : public NodeI
{
  public:
	bool test(char c);
};
class NotNumberNode : public NodeI
{
  public:
	bool test(char c);
};
class WhiteSpaceNode : public NodeI
{
  public:
	bool test(char c);
};
class NotWhiteSpaceNode : public NodeI
{
  public:
	bool test(char c);
};
class DotNode : public NodeI
{
  public:
	bool test(char c);
};
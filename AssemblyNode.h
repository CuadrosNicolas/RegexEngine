#pragma once
#include "NodeI.h"
#include "CharFunction.h"
/**
 * @brief
 * Node to match word type character
 */
class WordNode : public NodeI
{
  public:
	bool test(char c);
};
/**
 * @brief
 * Node to match not word type character
 */
class NotWordNode : public NodeI
{
  public:
	bool test(char c);
};
/**
 * @brief
 * Node to match number type character [0-9]
 */
class NumberNode : public NodeI
{
  public:
	bool test(char c);
};
/**
 * @brief
 * Node to match not number type character [^0-9]
 */
class NotNumberNode : public NodeI
{
  public:
	bool test(char c);
};
/**
 * @brief
 * Node to match whitespace type character
 */
class WhiteSpaceNode : public NodeI
{
  public:
	bool test(char c);
};
/**
 * @brief
 * Node to match not whitespace type character
 */
class NotWhiteSpaceNode : public NodeI
{
  public:
	bool test(char c);
};
/**
 * @brief
 * Node to match any type of character except line break
 */
class DotNode : public NodeI
{
  public:
	bool test(char c);
};
#pragma once
#include "EngineState.h"
#include "BuildState.h"
#include <exception>
/**
 * @brief
 * Exception throws when a quantifier is not well written
 */
class BadCounterNotation : public std::exception
{
	public:
	BadCounterNotation();
	const char* what();
};
/**
 * @brief
 * State for detecting user defined counter ({X,Y})
 */
class CounterState : public EngineState
{
  public:
	CounterState(Engine *e,DecoratorNode* D);
	EngineState *parse(char c);
	int convertToInt();
  private:
  int i;
  bool minSet;
	DecoratorNode *temp;
	std::string number;
};
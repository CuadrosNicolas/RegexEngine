#pragma once
#include "EngineState.h"
#include "BuildState.h"
#include <exception>
class BadCounterNotation : public std::exception
{
	public:
	BadCounterNotation();
	const char* what();
};
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
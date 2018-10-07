#pragma once
#include "EngineState.h"
#include "BuildState.h"
#include "Counter.h"
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
	CounterState(Engine *e);
	EngineState *parse(char c);
	int convertToInt();
  private:
  int i;
  bool minSet;
	Counter *temp;
	std::string number;
};
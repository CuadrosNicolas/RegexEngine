#pragma once
#include "CharNode.h"
#include "EngineState.h"
#include "BuildState.h"
class GroupState : public EngineState
{
	public:
		GroupState(Engine *e);
		EngineState* parse(char c);
};

class GroupTypeState : public EngineState
{
  public:
	GroupTypeState(Engine *e);
	EngineState *parse(char c);
};
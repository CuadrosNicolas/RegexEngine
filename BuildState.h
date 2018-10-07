#pragma once
#include "EngineState.h"
#include "SetState.h"
#include "EscapeState.h"
#include "CounterState.h"
#include "AssemblyNode.h"
#include "CharNode.h"
class BuildState : public EngineState
{
  public:
		BuildState(Engine *e);
		EngineState *parse(char c);
	private:
		NodeI* temp;
};
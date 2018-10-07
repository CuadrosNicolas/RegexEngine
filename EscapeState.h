#pragma once
#include "EngineState.h"
#include "BuildState.h"
#include "CharNode.h"
#include "AssemblyNode.h"
class EscapeState : public EngineState
{
  public:
	EscapeState(Engine *e);
	EngineState *parse(char c);
	protected:
	void addChar(char c);
};
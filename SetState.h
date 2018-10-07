#pragma once
#include "EngineState.h"
#include "SetNode.h"
#include "BuildState.h"
class SetState : public EngineState
{
  public:
	SetState(Engine *e);
	EngineState *parse(char c);

  private:
  	bool first;
	bool range;
	SetNode* temp;
	char char_temp;
};
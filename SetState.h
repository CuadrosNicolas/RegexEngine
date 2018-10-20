#pragma once
#include "EngineState.h"
#include "SetNode.h"
#include "BuildState.h"
/**
 * @brief
 * State of the regex engine use to read set ([...])
 */
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
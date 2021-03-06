#pragma once
#include "EngineState.h"
#include "SetState.h"
#include "EscapeState.h"
#include "CounterState.h"
#include "AssemblyNode.h"
#include "CharNode.h"
#include "AnchorNode.h"
#include "GroupEndNode.h"
#include "GroupState.h"
#include "StrState.h"
/**
 * @brief
 * Primary state of the Regex engine
 */
class BuildState : public EngineState
{
  public:
		BuildState(Engine *e);
		EngineState *parse(char c);

	private:
		NodeI* temp;
};
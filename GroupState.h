#pragma once
#include "CharNode.h"
#include "EngineState.h"
#include "BuildState.h"
/**
 * @brief
 * State use to detect a group in a regex
 */
class GroupState : public EngineState
{
	public:
		GroupState(Engine *e);
		EngineState* parse(char c);
};
/**
 * @brief
 * State use to detect  a type of a group if it has one (lookahead, negative lookahead, and non capturing groups)
 */
class GroupTypeState : public EngineState
{
  public:
	GroupTypeState(Engine *e);
	EngineState *parse(char c);
};
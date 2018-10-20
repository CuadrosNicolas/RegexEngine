#pragma once
#include "EngineState.h"
#include "BuildState.h"
#include "CharNode.h"
#include "AssemblyNode.h"
/**
 * @brief
 * State which identify the escaped character such as whitespace or character class like \s or \w for example
 */
class EscapeState : public EngineState
{
  public:
	EscapeState(Engine *e);
	EngineState *parse(char c);
	protected:
	void addChar(char c);
};
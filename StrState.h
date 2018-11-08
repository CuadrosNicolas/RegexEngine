#pragma once
#include "EngineState.h"
#include "BuildState.h"
#include "StrNode.h"
class StrState : public EngineState
{
	public:
		StrState(Engine *e,char c);
		EngineState *parse(char c);
		virtual void validate();

	  private:
		std::string actualValue;
};
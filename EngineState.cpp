#include "EngineState.h"
EngineState::EngineState(Engine *e) { parentEngine = e; };
EngineState* EngineState::parse(char c)
{
	return this;
}
#include "EngineState.h"
EngineState::EngineState(Engine *e) { parentEngine = e; };
EngineState::~EngineState()
{

}
EngineState* EngineState::parse(char c)
{
	return this;
}
void EngineState::addNode(NodeI *node)
{
	parentEngine->getPrevious()->link(node);
	node->setPred(parentEngine->getPrevious());
	parentEngine->setPrevious(node);
}
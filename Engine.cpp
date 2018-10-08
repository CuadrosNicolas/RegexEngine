#include "Engine.h"
#include "BuildState.h"
Engine* Engine::globalEngine=nullptr;
NodeI* Engine::BuildRegex(std::string s)
{
	if(globalEngine==nullptr)
	{
		globalEngine = new Engine();
	}
	return globalEngine->build(s);
}
Engine::Engine()
{

}
NodeI* Engine::build(std::string s)
{
	State = new BuildState(this);
	RegTree = new BeginNode();
	previous = this->RegTree;
	Reg = s;
	EngineState* temp = nullptr;
	for(char c : Reg)
	{
		temp = State->parse(c);
		if(temp!=State)
		{
			delete State;
			State = temp;
		}
	}
	previous->link(new EndNode());
	return RegTree;
}

NodeI *Engine::getPrevious()
{
	return previous;
}
void Engine::setPrevious(NodeI* node)
{
	previous = node;
}
DecoratorVisitor *Engine::getDecorator()
{
	return &Decorator;
}
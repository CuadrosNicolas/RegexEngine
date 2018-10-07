#include "Engine.h"
#include "BuildState.h"
Engine::Engine(std::string s)
{
	State = new BuildState(this);
	RegTree = new BeginNode();
	previous = this->RegTree;
	Reg = s;
	build();
}
void Engine::build()
{
	EngineState* temp = nullptr;
	for(char c : Reg)
	{
		temp = State->parse(c);
		if(temp!=State)
			State = temp;
	}
	previous->link(new EndNode());
}
std::vector<std::string> Engine::match(std::string s)
{
	StringIterator it(&s);
	std::vector<std::string> match;
	while(it.end()==false)
	{
		it = this->RegTree->in(it);
		if(it.isValid())
		{
			match.push_back(it.getValue());
		}
		else
		{
			it = it +1;
		}
		it.reinit();
	}
	return match;
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
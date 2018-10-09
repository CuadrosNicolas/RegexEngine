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
	RegTree = new GroupBeginNode();
	previous = this->RegTree;
	Reg = s;
	EngineState* temp = nullptr;
	groupStack = std::stack<NodeI*>();
	terminalNode.clear();
	groupStack.push(RegTree);
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
DecoratorVisitor *Engine::getVisitor(char c)
{
	VisitorCounter.setMode(c);
	return &VisitorCounter;
}

std::stack<NodeI*>& Engine::getStack()
{
	return groupStack;
}

std::vector<NodeI*>& Engine::getTerminal()
{
	return terminalNode;
}

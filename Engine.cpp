#include "Engine.h"
#include "BuildState.h"
Engine* Engine::globalEngine=nullptr;
NodeI* Engine::BuildRegex(std::string s,int F)
{
	if(globalEngine==nullptr)
	{
		globalEngine = new Engine();
	}
	globalEngine->Flag = F;
	return globalEngine->build(s);
}
TreeCouple *Engine::GenBody(std::string s, int F)
{
	if (globalEngine == nullptr)
	{
		globalEngine = new Engine();
	}
	globalEngine->Flag = F;
	return globalEngine->BuildBody(s);
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
	groupStack = std::stack<NodeI*>();
	terminalNode.clear();
	terminalNode.push_back(std::vector<NodeI*>());
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
	State->validate();
	NodeI* temp_newNode = new EndNode();
	NodeI *temp_n;
	while (!terminalNode.back().empty())
	{
		temp_n = terminalNode.back().back();
		temp_n->link(temp_newNode);
		terminalNode.back().pop_back();
	}
	previous->link(temp_newNode);
	terminalNode.pop_back();
	previous = temp_newNode;
	return RegTree;
}

TreeCouple *Engine::BuildBody(std::string s)
{
	GroupBeginNode* begin;
	GroupEndNode *end;
	State = new BuildState(this);
	begin = new GroupBeginNode();
	RegTree = begin;
	previous = this->RegTree;
	Reg = s;
	EngineState *temp = nullptr;
	groupStack = std::stack<NodeI *>();
	terminalNode.clear();
	terminalNode.push_back(std::vector<NodeI *>());
	groupStack.push(RegTree);
	for (char c : Reg)
	{
		temp = State->parse(c);
		if (temp != State)
		{
			delete State;
			State = temp;
		}
	}
	State->validate();
	GroupEndNode *temp_newNode = new GroupEndNode(begin);
	NodeI *temp_n;
	while (!terminalNode.back().empty())
	{
		temp_n = terminalNode.back().back();
		temp_n->link(temp_newNode);
		terminalNode.back().pop_back();
	}
	previous->link(temp_newNode);
	terminalNode.pop_back();
	previous = temp_newNode;
	end = temp_newNode;
	TreeCouple* out = new TreeCouple({begin,end});
	return out;
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
std::stack<Engine::groupType> &Engine::getGroupStack()
{
	return groupTypeStack;
}
std::vector<std::vector<NodeI*> >& Engine::getTerminal()
{
	return terminalNode;
}
int Engine::getFlag()
{
	return Flag;
}
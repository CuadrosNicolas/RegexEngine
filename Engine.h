#pragma once
#include "GroupBeginNode.h"
#include "EndNode.h"
#include "DecoratorVisitor.h"
#include <stack>
class EngineState;
class Engine
{
	public:
		static NodeI* BuildRegex(std::string s);
		NodeI* getPrevious();
		void setPrevious(NodeI* node);
		DecoratorVisitor *getVisitor(char c);
		std::stack<NodeI*>& getStack();
		std::vector<NodeI*>& getTerminal();
	protected:
		NodeI* build(std::string s);
		Engine();
		NodeI* previous;
		DecoratorVisitor VisitorCounter;

	  private:
		static Engine* globalEngine;
		GroupBeginNode* RegTree;
		std::string Reg;
		EngineState* State;
		std::stack<NodeI*> groupStack;
		std::vector<NodeI*> terminalNode;
};
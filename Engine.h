#pragma once
#include "GroupBeginNode.h"
#include "EndNode.h"
#include "DecoratorVisitor.h"
#include "RegFlags.h"
#include <stack>
class EngineState;
class Engine
{
	public:
		static NodeI* BuildRegex(std::string s,int F=NONE);
		NodeI* getPrevious();
		void setPrevious(NodeI* node);
		DecoratorVisitor *getVisitor(char c);
		std::stack<NodeI*>& getStack();
		std::vector<std::vector<NodeI *>> &getTerminal();
		int getFlag();
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
		std::vector<std::vector<NodeI*> > terminalNode;
		int Flag;
};
#pragma once
#include "GroupBeginNode.h"
#include "EndNode.h"
#include "DecoratorVisitor.h"
#include "RegFlags.h"
#include <stack>
class EngineState;
/**
 * @brief
 * Engine that build regex, using the singleton pattern.
 *
 */
class Engine
{
	public:
		enum groupType{
			GROUP,
			NCGROUP,
			LKAHGROUP,
		};
		static NodeI* BuildRegex(std::string s,int F=NONE);
		NodeI* getPrevious();
		void setPrevious(NodeI* node);
		DecoratorVisitor *getVisitor(char c);
		std::stack<NodeI*>& getStack();
		std::stack<groupType> &getGroupStack();
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
		std::stack<groupType> groupTypeStack;
		std::vector<std::vector<NodeI*> > terminalNode;
		int Flag;
};
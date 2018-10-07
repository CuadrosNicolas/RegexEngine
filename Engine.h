#pragma once
#include "BeginNode.h"
#include "EndNode.h"
#include "DecoratorVisitor.h"
#include <vector>
class EngineState;
class Engine
{
	public:
		Engine(std::string s);
		void build();
		std::vector<std::string> match(std::string s);
		NodeI* getPrevious();
		void setPrevious(NodeI* node);
		DecoratorVisitor* getDecorator();
	protected:
		NodeI* previous;
		DecoratorVisitor Decorator;
	private:
		BeginNode* RegTree;
		std::string Reg;
		EngineState* State;
};
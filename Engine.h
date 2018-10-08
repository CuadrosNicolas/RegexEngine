#pragma once
#include "BeginNode.h"
#include "EndNode.h"
#include "DecoratorVisitor.h"
class EngineState;
class Engine
{
	public:
		static NodeI* BuildRegex(std::string s);
		NodeI* getPrevious();
		void setPrevious(NodeI* node);
		DecoratorVisitor* getDecorator();
	protected:
		NodeI* build(std::string s);
		Engine();
		NodeI* previous;
		DecoratorVisitor Decorator;
	private:
		static Engine* globalEngine;
		BeginNode* RegTree;
		std::string Reg;
		EngineState* State;
};
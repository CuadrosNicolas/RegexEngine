#pragma once
#include "NodeI.h"
#include "GroupEndNode.h"
#include <exception>
#include "Counter.h"
class exceptionCounter : std::exception
{
	public:
		exceptionCounter(){

		};
		virtual const char * what() const throw()
		{
			return "You can't add a quantifier on a quantifier.";
		};
};

class DecoratorVisitor
{
	public:
	  DecoratorVisitor();
	  DecoratorNode *visit(NodeI *node);
	  DecoratorNode *visit(Counter *node);
	  DecoratorNode *visit(GroupEndNode *node);
	  void setMode(char c);
	protected:
		char mode;
};
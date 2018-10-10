#pragma once
#include "NodeI.h"
#include "Counter.h"
#include "Lazy.h"
#include "GroupEndNode.h"
#include "GroupCounter.h"
#include <exception>
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
	  NodeI *visit(NodeI *node);
	  NodeI *visit(Counter *node);
	  NodeI *visit(BeginGroupCounter *node);
	  NodeI *visit(GroupEndNode *node);
	  void setMode(char c);
	protected:
		char mode;
};
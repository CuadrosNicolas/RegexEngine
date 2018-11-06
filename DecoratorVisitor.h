#pragma once
#include "NodeVisitor.h"
#include <exception>
/**
 * @brief
 * Exception throws when a quantifier is applied on an other quantifier
 */
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
/**
 * @brief
 * Class that allows to build a counter node around an other in function of his type
 */
class DecoratorVisitor : public NodeVisitor
{
	public:
	  DecoratorVisitor();
	  NodeI *visit(NodeI *node);
	  NodeI *visit(Counter *node);
	  NodeI *visit(GroupEndNode *node);
	  NodeI *visit(NonCapturingGroupEndNode *node);
	  NodeI *visit(LookAheadNode *node);
	  NodeI *visit(NegLookAheadNode *node);

	  void setMode(char c);
	protected:
		char mode;
};
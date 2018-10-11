#include "DecoratorVisitor.h"
void DecoratorVisitor::setMode(char c)
{
	mode =c ;
}
DecoratorVisitor::DecoratorVisitor()
{

 }

 DecoratorNode *DecoratorVisitor::visit(NodeI *node)
 {
	 switch(mode)
	 {
		 case '?':
		 	return Counter::interrogation(node);
		 break;
		 case '*':
		 	return Counter::Star(node);
		 break;
		 case '+':
		 	return Counter::Plus(node);
		 break;
	 }
	 return nullptr;
 }
 DecoratorNode *DecoratorVisitor::visit(Counter *node)
 {
	 switch (mode)
	 {
	 case '?':
		 return new Lazy(node);
		 break;
	 case '*':
		 throw exceptionCounter();
		 break;
	 case '+':
		 throw exceptionCounter();
		 break;
	 }
	 return nullptr;
 }
 DecoratorNode *DecoratorVisitor::visit(BeginGroupCounter *node)
 {
	 switch (mode)
	 {
	 case '?':
		 return new GroupLazy(node);
		 break;
	 case '*':
		 throw exceptionCounter();
		 break;
	 case '+':
		 throw exceptionCounter();
		 break;
	 }
	 return nullptr;
 }
 DecoratorNode *DecoratorVisitor::visit(GroupEndNode *node)
 {
	 EndGroupCounter* temp_end;
	 switch (mode)
	 {
		case '?':
			temp_end = new EndGroupCounter(0,1);
			break;
		case '*':
			temp_end = new EndGroupCounter(0,-1);
			break;
		case '+':
			temp_end = new EndGroupCounter(1,-1);
			break;
	 }
	BeginGroupCounter *temp_beg = new BeginGroupCounter(temp_end, node->getPred());
	temp_beg->setPred(node->getPred()->getPred());
	node->getPred()->getPred()->setNext(temp_beg);
	node->link(temp_end);
	return temp_beg;
 }
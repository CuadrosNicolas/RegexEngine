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
	 BeginGroupCounter *temp_beg;
	switch (mode)
	 {
		case '?':
			temp_beg = new BeginGroupCounter(temp_end, node->getPred(),0,1);
			break;
		case '*':
			temp_beg = new BeginGroupCounter(temp_end, node->getPred(),0,-1);
			break;
		case '+':
			temp_beg = new BeginGroupCounter(temp_end, node->getPred(),1,-1);
			break;
	 }
	temp_beg->setPred(node->getPred()->getPred());
	temp_beg->setEnd(node);
	node->getPred()->getPred()->setNext(temp_beg);
	node->link(temp_beg);
	return temp_beg;
 }


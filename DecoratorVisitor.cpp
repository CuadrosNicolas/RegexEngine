#include "DecoratorVisitor.h"
DecoratorVisitor::DecoratorVisitor()
{

}
NodeI* DecoratorVisitor::visit(NodeI *node)
{
	return Counter::interrogation(node);
}
NodeI *DecoratorVisitor::visit(Counter *node)
{
	return new Lazy(node);
}
NodeI *DecoratorVisitor::visit(GroupEndNode* node)
{
	//Counter::interrogation(node);
	return node;
}

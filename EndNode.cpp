#include "EndNode.h"
#include "NodeVisitor.h"
EndNode::EndNode()
{

}
bool EndNode::test(char c)
{
	return true;
}
StringIterator EndNode::in(StringIterator it)
{
	return it.validPos();
}
NodeI *EndNode::accept(NodeVisitor *v)
{
	return v->visit(this);
}
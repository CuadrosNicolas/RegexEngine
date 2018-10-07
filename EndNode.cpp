#include "EndNode.h"

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
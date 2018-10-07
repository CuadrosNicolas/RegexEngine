#include "BeginNode.h"

BeginNode::BeginNode()
{

}
bool BeginNode::test(char c)
{
	return true;
}
StringIterator BeginNode::in(StringIterator it)
{
	return this->next->in(it);
}
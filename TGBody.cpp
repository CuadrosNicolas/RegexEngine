#include "TGBody.h"

TGBody::TGBody()
{
	end = nullptr;
	begin=nullptr;
}
void TGBody::setBegin(GroupBeginNode *b)
{
	begin = b;
}
void TGBody::setEnd(NodeI *e)
{
	end = e;
}

GroupBeginNode *TGBody::getBegin()
{
	return begin;
}
NodeI *TGBody::getEnd()
{
	return end;
}
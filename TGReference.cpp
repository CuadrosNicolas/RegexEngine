#include "TGReference.h"
#include "TGBuilder.h"
TGReference::TGReference(TGBuilder* b,int r)
{
	builder = b;
	ref = r;
}
TGReference::TGReference(const TGReference& RRef)
{
	if (isInit == false)
	{

		builder = RRef.builder;
		ref = RRef.ref;
		isInit = true;
	}
	else
	{
		builder->access(ref)->setNext(builder->access(RRef.ref));
		builder->accessEnd(RRef.ref)->setNext(builder->accessEnd(ref));
	}
}
TGReference TGReference::operator+(TGReference RRef)
{
	TGReference out(builder,-1);
	if(ref!=-1)
	{
		LinkNode *tem_b = new LinkNode(builder->access(ref));
		LinkNode* temp = new LinkNode(builder->access(RRef.ref));
		builder->Prepare(temp,tem_b);
	}
	else
	{
		LinkNode *temp = new LinkNode(builder->access(RRef.ref));
		builder->Prepare(temp);
	}
	return out;
}

TGReference& TGReference::operator=(const TGReference& RRef)
{
	if(isInit==false)
	{

		builder = RRef.builder;
		ref = RRef.ref;
		isInit = true;
	}
	else
	{
		builder->access(ref)->setNext(builder->access(RRef.ref));
		builder->accessEnd(RRef.ref)->setNext(builder->accessEnd(ref));
	}
	return *this;
}

int TGReference::getIndex()
{
	return ref;
}
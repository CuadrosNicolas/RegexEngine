#pragma once
#include "TGBody.h"
#include "LinkNode.h"
class TGBuilder;
class TGReference
{
	public:

		TGReference(TGBuilder* b,int r);
		TGReference(const TGReference& RRef);
		int getIndex();
		virtual TGReference operator+(TGReference RRef);
		TGReference& operator=(const TGReference& RRef);
	private:
		bool isInit=false;
		int ref;
		TGBuilder* builder;
};
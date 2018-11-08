#pragma once
#include "GroupBeginNode.h"
#include "GroupEndNode.h"
class TGBody{
	public:
		TGBody();
		void setBegin(GroupBeginNode* b);
		void setEnd(NodeI *e);
		GroupBeginNode *getBegin();
		NodeI *getEnd();

	  private:
		GroupBeginNode* begin;
		NodeI* end;
};
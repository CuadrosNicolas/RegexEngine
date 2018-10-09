#pragma once
#include "NodeI.h"

class GroupBeginNode : public NodeI
{
	public:
		GroupBeginNode();
		NodeI* add(NodeI *next);
		NodeI* link(NodeI* next);
		StringIterator in(StringIterator it);
		void setNext(NodeI* node);
		void setPred(NodeI* node);
		bool test(char c);
	protected:
		std::vector<NodeI*> children;
		bool alreadyPush;
};
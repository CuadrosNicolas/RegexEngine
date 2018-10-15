#pragma once
#include "NodeI.h"
#include "EndNode.h"
class GroupBeginNode : public NodeI
{
	public:
		GroupBeginNode();
		NodeI* add(NodeI *next);
		NodeI* link(NodeI* next);
		virtual StringIterator in(StringIterator it);
		void setNext(NodeI* node);
		void setPred(NodeI* node);
		bool test(char c);
		virtual NodeI* accept(DecoratorVisitor* v);
	protected:
		std::vector<NodeI*> children;
};
class NonCapturingGroupBeginNode : public GroupBeginNode
{
  public:
	NonCapturingGroupBeginNode();
	virtual StringIterator in(StringIterator it);
	virtual NodeI *accept(DecoratorVisitor *v);
};

class LookAheadNode : public NodeI
{
		public:
			LookAheadNode();
			NodeI* getIntern();
			void setEnd(NodeI* n);
			virtual NodeI *link(NodeI *Next);
			virtual StringIterator in(StringIterator it);
			virtual NodeI *accept(DecoratorVisitor *v);
			virtual NodeI* get();
			void Valid();
		protected:
			NodeI* valider;
			NodeI* internGroup;
			NodeI* groupLast;
};
class NegLookAheadNode : public LookAheadNode
{
public:
	NegLookAheadNode();
	virtual StringIterator in(StringIterator it);
};
class BeginNode : public GroupBeginNode
{
  public:
	BeginNode();
	StringIterator in(StringIterator it);
	virtual NodeI *accept(DecoratorVisitor *v);
};
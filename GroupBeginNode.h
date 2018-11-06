#pragma once
#include "NodeI.h"
#include "EndNode.h"
class NodeCopier;
class GroupBeginNode : public NodeI
{
	public:
	friend class NodeCopier;
		GroupBeginNode();
		virtual ~GroupBeginNode();
		NodeI* add(NodeI *next);
		NodeI* link(NodeI* next);
		virtual StringIterator in(StringIterator it);
		void setNext(NodeI* node);
		void setPred(NodeI* node);
		bool test(char c);
		virtual NodeI *accept(NodeVisitor *v);

	  protected:
		std::vector<NodeI*> children;
};
class NonCapturingGroupBeginNode : public GroupBeginNode
{
  public:
		friend class NodeCopier;
		NonCapturingGroupBeginNode();
		virtual StringIterator in(StringIterator it);
		virtual NodeI *accept(NodeVisitor *v);
};

class LookAheadNode : public NodeI
{
		public:
			friend class NodeCopier;
			friend class DecoratorVisitor;
			LookAheadNode();
			~LookAheadNode();
			NodeI* getIntern();
			void setEnd(NodeI* n);
			virtual NodeI *link(NodeI *Next);
			virtual StringIterator in(StringIterator it);
			virtual NodeI *accept(NodeVisitor *v);
			virtual NodeI* get();
			void Valid();
		protected:
			NodeI* valider;
			NodeI* next_in;
			NodeI* groupLast;
};
class NegLookAheadNode : public LookAheadNode
{
public:
	friend class NodeCopier;
	NegLookAheadNode();
	virtual StringIterator in(StringIterator it);
	virtual NodeI *accept(NodeVisitor *v);
};
class BeginNode : public GroupBeginNode
{
  public:
		friend class NodeCopier;
		BeginNode();
		StringIterator in(StringIterator it);
		virtual NodeI *accept(NodeVisitor *v);
};
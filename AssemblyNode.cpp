#include "AssemblyNode.h"
#include "NodeVisitor.h"
 bool WordNode::test(char c)
 {
	 return Word(c);
 }
 NodeI *WordNode::accept(NodeVisitor *v)
 {
	 return v->visit(this);
 }
 bool NotWordNode::test(char c)
 {
	 return !Word(c);
 }
 NodeI *NotWordNode::accept(NodeVisitor *v)
 {
	 return v->visit(this);
 }
 bool NumberNode::test(char c)
 {
	 return Number(c);
 }
 NodeI *NumberNode::accept(NodeVisitor *v)
 {
	 return v->visit(this);
 }
 bool NotNumberNode::test(char c)
 {
	 return !Number(c);
 }
 NodeI *NotNumberNode::accept(NodeVisitor *v)
 {
	 return v->visit(this);
 }
 bool WhiteSpaceNode::test(char c)
 {
	 return WhiteSpace(c);
 }
 NodeI *WhiteSpaceNode::accept(NodeVisitor *v)
 {
	 return v->visit(this);
 }
 bool NotWhiteSpaceNode::test(char c)
 {
	 return !WhiteSpace(c);
 }
 NodeI *NotWhiteSpaceNode::accept(NodeVisitor *v)
 {
	 return v->visit(this);
 }
 bool DotNode::test(char c)
 {
	 return !(c == '\r' || c == '\n');
 }
 NodeI *DotNode::accept(NodeVisitor *v)
 {
	 return v->visit(this);
 }
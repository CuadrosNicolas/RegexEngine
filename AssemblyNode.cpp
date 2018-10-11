#include "AssemblyNode.h"

 bool WordNode::test(char c)
 {
	 return Word(c);
 }

 bool NotWordNode::test(char c)
 {
	 return !Word(c);
 }

 bool NumberNode::test(char c)
 {
	 return Number(c);
 }

 bool NotNumberNode::test(char c)
 {
	 return !Number(c);
 }

 bool WhiteSpaceNode::test(char c)
 {
	 return WhiteSpace(c);
 }

 bool NotWhiteSpaceNode::test(char c)
 {
	 return !WhiteSpace(c);
 }

 bool DotNode::test(char c)
 {
	 return !(c == '\r' || c == '\n');
 }

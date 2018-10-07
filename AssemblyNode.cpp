#include "AssemblyNode.h"

 bool WordNode::test(char c)
 {
	 return (c>= 'A' && c<= 'Z') ||
	 (c>='a' && c<='z') || (c>='0' && c<=9) || c=='_';
 }

 bool NotWordNode::test(char c)
 {
	 return !((c >= 'A' && c <= 'Z') ||
			(c >= 'a' && c <= 'z') || (c >= '0' && c <= 9) || c == '_');
 }

 bool NumberNode::test(char c)
 {
	 return (c >= '0' && c <= 9);
 }

 bool NotNumberNode::test(char c)
 {
	 return !(c >= '0' && c <= 9);
 }

 bool WhiteSpaceNode::test(char c)
 {
	 return (c == '\t' || c == '\r' || c=='\n');
 }

 bool NotWhiteSpaceNode::test(char c)
 {
	 return !(c == '\t' || c == '\r' || c == '\n');
 }

 bool DotNode::test(char c)
 {
	 return !(c == '\r' || c == '\n');
 }

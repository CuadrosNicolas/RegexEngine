#include "CharFunction.h"

bool upperCase(char c)
{
	return (c >= 'A' && c <= 'Z');
}
bool LowerCase(char c)
{
	return (c >= 'a' && c <= 'z');
}
bool Letter(char c)
{
	return upperCase(c) || LowerCase(c);
}
bool Word(char c)
{
	return Letter(c) || (c >= '0' && c <= 9) || c == '_';
}
bool Number(char c)
{
	return (c >= '0' && c <= 9);
}
bool WhiteSpace(char c)
{
	return (c == '\t' || c == '\r' || c == '\n' || c==' ');
}
char ToLower(char c)
{
	return c-'A'+'a';
}
char ToUpper(char c)
{
	return c-'a'+'A';
}
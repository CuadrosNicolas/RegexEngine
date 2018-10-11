#include "SetState.h"

SetState::SetState(Engine *e) : EngineState(e)
{
	char_temp=-1;
	temp = getSetNode(e->getFlag());
	range = false;
	first = true;
}
EngineState *SetState::parse(char c)
{
	if(first)
	{
		if(char_temp==-1 && c=='^')
		{
			temp->setNot();
		}
		first = false;
	}
	if(char_temp==-1 and c!=']')
	{
		char_temp=c;
	}
	else if(c=='-' and char_temp!=-1)
	{
		range = true;
	}
	else if(range)
	{
		range = false;
		temp->addSet(char_temp,c);
		char_temp=-1;
	}
	else if (c != ']')
	{
		temp->addChar(char_temp);
		char_temp = c;
	}
	else
	{
		if(char_temp!=-1)
			temp->addChar(char_temp);
		parentEngine->getPrevious()->link(temp);
		temp->setPred(parentEngine->getPrevious());
		parentEngine->setPrevious(temp);
		return new BuildState(this->parentEngine);
	}
	return this;
}

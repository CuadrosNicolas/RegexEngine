#include "StrState.h"

StrState::StrState(Engine *e,char c): EngineState(e)
{
	actualValue = c;
}

EngineState* StrState::parse(char c)
{
	if(c!='*' && c!='?' && c!='+' && c!= '[' && c!= ']'
		&& c!='\\' && c!= '^' && c!='$' && c!='|' && c!='(' && c!=')')
	{
		if (c != '\t' && c != '\n' && c != '\r')
		{
			actualValue += c;
			return this;
		}
	}
	else
	{
		if(actualValue.size()>1)
		{
			StrNode* temp =new StrNode(actualValue);
			parentEngine->getPrevious()->link(temp);
			temp->setPred(parentEngine->getPrevious());
			parentEngine->setPrevious(temp);
		}
		else
		{
			NodeI* temp = getCharNode(actualValue[0], parentEngine->getFlag());
			parentEngine->getPrevious()->link(temp);
			temp->setPred(parentEngine->getPrevious());
			parentEngine->setPrevious(temp);
		}
		return (new BuildState(parentEngine))->parse(c);
	}
	return this;
}
void StrState::validate()
{
	if (actualValue.size() > 1)
	{
		NodeI *temp = getStrNode(actualValue, parentEngine->getFlag());
		parentEngine->getPrevious()->link(temp);
		temp->setPred(parentEngine->getPrevious());
		parentEngine->setPrevious(temp);
	}
	else
	{
		NodeI *temp = getCharNode(actualValue[0], parentEngine->getFlag());
		parentEngine->getPrevious()->link(temp);
		temp->setPred(parentEngine->getPrevious());
		parentEngine->setPrevious(temp);
	}
}
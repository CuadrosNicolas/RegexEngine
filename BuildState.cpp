#include "BuildState.h"
BuildState::BuildState(Engine* e):EngineState(e)
{

}
EngineState* BuildState::parse(char c)
{
	switch (c)
	{
	case '*':
		parentEngine->setPrevious(Counter::Star(parentEngine->getPrevious()));
		break;
	case '?':
		parentEngine->setPrevious(parentEngine->getPrevious()->accept(parentEngine->getDecorator()));
		break;
	case '+':
		parentEngine->setPrevious(Counter::Plus(parentEngine->getPrevious()));
		break;
	case '[':
		return new SetState(parentEngine);
		break;
	case '\\':
		return new EscapeState(parentEngine);
		break;
	case '{':
		return new CounterState(parentEngine);
	break;
	case '^':
		addNode(new AnchorBeginNode());
	break;
	case '$':
		addNode(new AnchorEndNode());
	break;
	case '.':
		temp = new DotNode();
		parentEngine->getPrevious()->link(temp);
		temp->setPred(parentEngine->getPrevious());
		parentEngine->setPrevious(temp);
		break;
	default:
		if (c != '\t' && c != '\n' && c != '\r')
		{
		temp = new CharNode(c);
		parentEngine->getPrevious()->link(temp);
		temp->setPred(parentEngine->getPrevious());
		parentEngine->setPrevious(temp);
		}
		break;
	}
	return this;
}
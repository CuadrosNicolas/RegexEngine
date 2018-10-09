#include "BuildState.h"
BuildState::BuildState(Engine *e) : EngineState(e)
{
}
EngineState *BuildState::parse(char c)
{
	switch (c)
	{
	case '*':
		parentEngine->setPrevious(parentEngine->getPrevious()->accept(parentEngine->getVisitor('*')));
		break;
	case '?':
		parentEngine->setPrevious(parentEngine->getPrevious()->accept(parentEngine->getVisitor('?')));
		break;
	case '+':
		parentEngine->setPrevious(parentEngine->getPrevious()->accept(parentEngine->getVisitor('+')));
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
	case '(':
		temp = new GroupBeginNode();
		parentEngine->getStack().push(temp);
		addNode(temp);
		break;
	case ')':
		temp = new GroupEndNode(parentEngine->getStack().top());
		parentEngine->getPrevious()->link(temp);
		parentEngine->setPrevious(temp);
		parentEngine->getStack().pop();
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
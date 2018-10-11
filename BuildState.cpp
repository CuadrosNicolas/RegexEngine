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
		return new CounterState(parentEngine, (DecoratorNode *)parentEngine->getPrevious()->accept(parentEngine->getVisitor('*')));
		break;
	case '^':
		if(parentEngine->getFlag()&MULTILINE)
			addNode(new AnchorMultiLineLeft());
		else
			addNode(new AnchorBeginNode());
		break;
	case '$':
		if(parentEngine->getFlag()&MULTILINE)
			addNode(new AnchorMultiLineRight());
		else
			addNode(new AnchorEndNode());
		break;
	case '|':
		parentEngine->getTerminal().back().push_back(parentEngine->getPrevious());
		parentEngine->setPrevious(parentEngine->getStack().top());
		break;
	case '(':
		temp = new GroupBeginNode();
		parentEngine->getStack().push(temp);
		parentEngine->getTerminal().push_back(std::vector<NodeI*>());
		addNode(temp);
		break;
	case ')':
		temp = new GroupEndNode(parentEngine->getStack().top());
		NodeI* temp_n;
		while(!parentEngine->getTerminal().back().empty())
		{
			temp_n = parentEngine->getTerminal().back().back();
			parentEngine->getTerminal().back().pop_back();
			temp_n->link(temp);
		}
		parentEngine->getPrevious()->link(temp);
		parentEngine->setPrevious(temp);
		parentEngine->getStack().pop();
		parentEngine->getTerminal().pop_back();
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
			temp = getCharNode(c,parentEngine->getFlag());
			parentEngine->getPrevious()->link(temp);
			temp->setPred(parentEngine->getPrevious());
			parentEngine->setPrevious(temp);
		}
		break;
	}
	return this;
}
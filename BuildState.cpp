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
		temp =parentEngine->getPrevious()->accept(parentEngine->getVisitor('*'));
		return new CounterState(parentEngine, (DecoratorNode *)temp->get());
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
		return new GroupState(parentEngine);
		break;
	case ')':
		switch(parentEngine->getGroupStack().top())
		{
			case Engine::groupType::GROUP:
				temp = new GroupEndNode(parentEngine->getStack().top());
			break;
			case Engine::groupType::NCGROUP:
				temp = new NonCapturingGroupEndNode(parentEngine->getStack().top());
				break;
			case Engine::groupType::LKAHGROUP:
				temp = new GroupEndNode(parentEngine->getStack().top());
				break;
			case Engine::groupType::NEGLKAHGROUP:
				temp = new GroupEndNode(parentEngine->getStack().top());
				break;
		}
		parentEngine->getGroupStack().pop();
		NodeI *temp_n;
		NodeI* temp_subEnd;
		if (parentEngine->getGroupStack().empty() ==false && parentEngine->getGroupStack().top() == Engine::groupType::LKAHGROUP)
		{
			temp_subEnd = parentEngine->getStack().top();
		}
		while (!parentEngine->getTerminal().back().empty())
		{
			temp_n = parentEngine->getTerminal().back().back();
			parentEngine->getTerminal().back().pop_back();
			temp_n->link(temp);
		}
		parentEngine->getPrevious()->link(temp);
		parentEngine->setPrevious(temp);
		parentEngine->getStack().pop();
		parentEngine->getTerminal().pop_back();
		if (parentEngine->getGroupStack().empty() == false && parentEngine->getGroupStack().top() == Engine::groupType::LKAHGROUP)
		{
			parentEngine->getGroupStack().pop();
			temp_n = parentEngine->getStack().top();
			parentEngine->setPrevious(temp_n);
			((LookAheadNode*)temp_n)->setEnd(temp);
			((LookAheadNode *)temp_n)->Valid();
			parentEngine->getStack().pop();
		}
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
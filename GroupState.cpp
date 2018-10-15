#include "GroupState.h"

GroupState::GroupState(Engine* e) : EngineState(e)
{

}
EngineState* GroupState::parse(char c)
{
	NodeI* temp;
	switch(c)
	{
		case '?':
			return new GroupTypeState(parentEngine);
		break;
		default:
			temp = new GroupBeginNode();
			parentEngine->getStack().push(temp);
			parentEngine->getTerminal().push_back(std::vector<NodeI *>());
			addNode(temp);
			parentEngine->getGroupStack().push(Engine::groupType::GROUP);
			return (new BuildState(parentEngine))->parse(c);
		break;
	}
	return nullptr;
}

GroupTypeState::GroupTypeState(Engine *e) : EngineState(e)
{
}
EngineState *GroupTypeState::parse(char c)
{
	NodeI* temp;
	switch (c)
	{
	case ':':
		temp = new NonCapturingGroupBeginNode();
		parentEngine->getStack().push(temp);
		parentEngine->getTerminal().push_back(std::vector<NodeI *>());
		addNode(temp);
		parentEngine->getGroupStack().push(Engine::groupType::NCGROUP);
		return new BuildState(parentEngine);
		break;
	case '=':
		temp = new LookAheadNode();
		parentEngine->getGroupStack().push(Engine::groupType::LKAHGROUP);
		parentEngine->getGroupStack().push(Engine::groupType::NCGROUP);
		parentEngine->getStack().push(temp);
		parentEngine->getStack().push(((LookAheadNode*)temp)->getIntern());
		parentEngine->getTerminal().push_back(std::vector<NodeI *>());
		addNode(temp);
		parentEngine->setPrevious(((LookAheadNode *)temp)->getIntern());
		return new BuildState(parentEngine);
		break;
	case '!':
		temp = new NegLookAheadNode();
		parentEngine->getGroupStack().push(Engine::groupType::LKAHGROUP);
		parentEngine->getGroupStack().push(Engine::groupType::NCGROUP);
		parentEngine->getStack().push(temp);
		parentEngine->getStack().push(((LookAheadNode *)temp)->getIntern());
		parentEngine->getTerminal().push_back(std::vector<NodeI *>());
		addNode(temp);
		parentEngine->setPrevious(((LookAheadNode *)temp)->getIntern());
		return new BuildState(parentEngine);
		break;
	default:
		throw std::exception();
		break;
	}
	return nullptr;
}
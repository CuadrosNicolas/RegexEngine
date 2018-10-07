#include "EscapeState.h"
EscapeState::EscapeState(Engine *e) : EngineState(e)
{
}
void EscapeState::addChar(char c)
{
	CharNode *temp = new CharNode(c);
	addNode(temp);
}
EngineState *EscapeState::parse(char c)
{
	switch (c)
	{
	case 't':
		addChar('\t');
		break;
	case 'n':
		addChar('\n');
		break;
	case 'r':
		addChar('\r');
		break;
	case 'w':
		addNode(new WordNode());
		break;
	case 'W':
		addNode(new NotWordNode());
		break;
	case 'd':
		addNode(new NumberNode());
		break;
	case 'D':
		addNode(new NotNumberNode());
		break;
	case 's':
		addNode(new WhiteSpaceNode());
		break;
	case 'S':
		addNode(new NotWhiteSpaceNode());
		break;
	case 'b':
		addNode(new AnchorWordBoundariesNode());
	break;
	case 'B':
		addNode(new AnchorNotWordBoundariesNode());
	break;
	default:
		addChar(c);
		break;
	}
	return new BuildState(parentEngine);
}
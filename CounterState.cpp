#include "CounterState.h"
BadCounterNotation::BadCounterNotation()
{

}
const char *BadCounterNotation::what(){
	return "Error, a counter contain a bad formed number.";
}

CounterState::CounterState(Engine *e,DecoratorNode* D) : EngineState(e)
{
	temp = D;
	e->setPrevious(temp);
	number = "";
	minSet = false;
}
int CounterState::convertToInt()
{
	return std::stoi(number);
}
EngineState *CounterState::parse(char c)
{
	switch (c)
	{
	case ',':
		i = convertToInt();
		temp->setMin(i);
		temp->setMax(-1);
		number = "";
		minSet = true;
	break;
	case '}':
		if(!minSet)
		{
			i = convertToInt();
			temp->setMin(i);
			temp->setMax(i);
			number="";
		}
		else if(number!= "")
		{
			i = convertToInt();
			temp->setMax(i);
		}
		return new BuildState(parentEngine);
	break;
	default:
		if(c>='0' && c<='9')
			number+=c;
		else
			throw BadCounterNotation();
		break;
	}
	return this;
}
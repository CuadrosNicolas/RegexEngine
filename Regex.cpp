#include "Regex.h"

Regex::Regex(std::string s,int F)
{
	Flag = F;
	regTree = Engine::BuildRegex(s,F);
	lastPos = 0;
	ForcedPos = 0;
}
Regex& Regex::SetPos(int i )
 {
	 ForcedPos = i;
	 return *this;
 }
 int Regex::getLastPos()
 {
	 return lastPos;
 }
Match Regex::matchString(const std::string  &s)
{
	StringIterator it(s);
	it.init();
	if(Flag & STICKY)
	{
		it.pos = ForcedPos;
	}
	while (it.end() == false)
	{
		it = regTree->in(it);
		if (!it.isValid())
		{
			it = it + 1;
		}
		else
		{
			lastPos = it.pos;
		}
		if( ((Flag & GLOBAL_SEARCH)==false || (Flag & STICKY)==true) && it.isValid()==true)
		{
			it.reinit();
			break;
		}
		it.reinit();
	}

	it.clean();
	//std::cout << it.getMatch()->getPrint() << std::endl;
	return *(it.getMatch());
}
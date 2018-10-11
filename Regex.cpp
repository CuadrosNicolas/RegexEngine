#include "Regex.h"

Regex::Regex(std::string s,int F)
{
	Flag = F;
	regTree = Engine::BuildRegex(s,F);
	lastPos = 0;
	ForcedPos = 0;
}
void Regex::SetPos(int i )
 {
	 ForcedPos = i;
 }
 int Regex::getLastPos()
 {
	 return lastPos;
 }
Match Regex::matchString(std::string s)
{
	StringIterator it(&s);
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
	matchs = *(it.getMatch());
	return matchs;
}
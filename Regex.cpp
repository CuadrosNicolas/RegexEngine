#include "Regex.h"

Regex::Regex(std::string s)
{
	regTree = Engine::BuildRegex(s);
}
Match Regex::matchString(std::string s)
{
	StringIterator it(&s);
	it.init();
	while (it.end() == false)
	{ 
		it = regTree->in(it);
		if (!it.isValid())
		{
			it = it + 1;
		}
		it.reinit();
	}

	it.clean();
	matchs = *(it.getMatch());
	return matchs;
}
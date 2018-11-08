#include <iostream>
#include "Regex.h"
#include "TGBuilder.h"
#include "TGReference.h"
int countMatch(Match* matchs)
{
	//Initialize the counter
	int counter = 0;
	//We don't count the first match because it's the root of all matches.
	//Count all the sub match
	for (Match *m : matchs->getChild())
	{
		counter+= countMatch(m);
		counter++;
	}
	return counter;
}

int main(int argc, char *argv[])
{
	TGBuilder Builder;
	TGReference number = Builder.Build("[0-9]+");
	TGReference plus = Builder.Build("\\s*\\+\\s*");
	TGReference Voi = Builder.Build("\\s*");
	TGReference add = Builder.Build(Voi+number+plus+number+Voi);
	Builder.SetMain(add);

	//Regex temp("(?!AS)*AB", GLOBAL_SEARCH | CASE_INSENSITIVE);
	//Create a string to match
	std::string test(" 752 + 6554");
	std::cout << "Matches : " << std::endl
			  << Builder.parse(test).getPrint() << std::endl;
	std::cin.get();
	return 0;
}
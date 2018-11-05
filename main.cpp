#include <iostream>
#include "Regex.h"
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
	Regex temp("((AB)*B)*", GLOBAL_SEARCH | CASE_INSENSITIVE);
	//Create a string to match
	std::string test("ABABABBB");
	std::cout << "Matches : " << std::endl
			  << temp.matchString(test).getPrint() << std::endl;
	std::cin.get();
	return 0;
}
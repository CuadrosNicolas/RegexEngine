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
	//Build the regex with a pattern to extract word
	//Here is an example with a pattern matching any word beginning with 'w'
	Regex temp("AB?A");
	//Create a string to match
	std::string test("ABA");
	//Try to match the pattern with the string
	Match matchs = temp.matchString(test);
	//Print the matches
	std::cout << matchs.getPrint() << std::endl;
	int counter = countMatch(&matchs);
	std::cout << "Number of matches : " << counter << std::endl;
	std::cin.get();
	return 0;
}
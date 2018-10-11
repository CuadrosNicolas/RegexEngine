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
	Regex temp("Hello World !",STICKY|CASE_INSENSITIVE);
	//Create a string to match
	std::string test("HeLLo World !\nHello WORLd !");
	//First match a the beginning of the string
	Match matchs = temp.matchString(test);
	std::cout <<"First match : "<< matchs.getPrint() << std::endl;
	//Move the regex to his last position in order to continue the parsing.
	temp.SetPos(temp.getLastPos());
	matchs = temp.matchString(test);
	//Print the result
	std::cout << "Second match : "<< matchs.getPrint() << std::endl;
	int counter = countMatch(&matchs);
	std::cout << "Number of matches : " << counter << std::endl;
	std::cin.get();
	return 0;
}
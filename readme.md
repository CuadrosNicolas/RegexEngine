# Introduction

This projet aims to make a small library to build and exploit Regex.

# Features

This library allows to use basic regex syntax :

 - Recognize text
 - Using set format like [a-zA-z_]
 - Quantifiers
	- \*
	- ?
	- \+
	- a{0,5}
	- Lazy quantifier using '?' after any others quantifiers
- Special character :
	- . everything except \n and \r
	- \t \n \r
	- \b \B for word and non word
	- \d \D for number and non number
	- \w \W for whitespace and non whitespace

- Anchor :
	- ^ $ : begin and end of string
	- \b \B word boundaries and non word boundaries
- Group :
	- Capture group using ('sub regex') , group does not support quantifiers (at this moment)

# Usage

In order to build and try to match a regex, please refer to the following steps :

1. Import the header
```C++
#include "Regex.h"
```
2. Create your regex with your pattern
3. Match your regex with a string
4. Exploit the matches

```C++
	//Build the regex with a pattern to extract word
	//Here is an example with a pattern matching any word beginning with 'w'
	Regex temp("\\b.+?\\b");
	//Create a string to match
	std::string test("wall wire whole");
	//Try to match the pattern with the string
	Match matchs = temp.matchString(test);
	//Print the matches
	std::cout << matchs.getPrint() << std::endl;
	int counter = countMatch(&matchs);
	std::cout << "Number of matches : " << counter << std::endl;
```

If you want to get a string representing the match, use the getPrint() method.

In order to iterate through a match, follow this example which build a function to count the number of matches countain in the result of a regex.
```C++
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
```

# ToDos

- [x] character support
- [x] Quantifier support
- [x] Set support
- [x] Special character support
- [x] Anchor support
- [x] Class for managing match and sub-match
- [x] Separate Engine in two class, one for building regex, and one for containing them
- [x] Capturing group
- [x] Adding quantifiers  support for groups
- [ ] Correcting Matchs depth bug
- [ ] Adding Lazy quantifiers support for groups
- [ ] Clean code related to groups
- [ ] Or '|'
- [ ] Flags managment
- [ ] non capturing group
- [ ] positive and negative lookahead
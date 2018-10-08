#include <iostream>
#include "Regex.h"
using namespace std;

int main(int argc,char* argv[])
{
	if(argc>=2)
	{
		//string temp_s = argv[1];
		string temp_s = ".*? ";
		Regex temp(temp_s);
		string test("AAA AAA AAA ");
		Match matchs = temp.matchString(test);
		cout << matchs.getPrint() << endl;

	}
	else
	{
		cout << "ERROR : Not enought arguments." << endl;
	}
	cin.get();
	return 0;
}
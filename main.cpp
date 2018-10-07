#include <iostream>
#include "Engine.h"
using namespace std;

int main(int argc,char* argv[])
{
	if(argc>=2)
	{
		//string temp_s = argv[1];
		string temp_s = "\\B.*\\Bt$";
		Engine temp(temp_s);
		string test("Salut");
		auto matchs = temp.match(test);
		for(auto match : matchs)
			cout << match << endl;
	}
	else
	{
		cout << "ERROR : Not enought arguments." << endl;
	}
	cin.get();
	return 0;
}
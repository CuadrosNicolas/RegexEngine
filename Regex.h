#pragma once
#include "Match.h"
#include "NodeI.h"
#include "Engine.h"
#include "Match.h"
class Regex
{
	public:
		Regex(std::string s,int F=NONE);
		Match matchString(const std::string &s);
		Regex& SetPos(int i);
		int getLastPos();
	private:
		NodeI* regTree;
		Match matchs;
		int Flag;
		int lastPos;
		int ForcedPos;

};
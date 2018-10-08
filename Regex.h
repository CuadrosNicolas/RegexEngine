#pragma once
#include "Match.h"
#include "NodeI.h"
#include "Engine.h"
#include "Match.h"
class Regex
{
	public:
		Regex(std::string s);
		Match matchString(std::string s);
	private:
		NodeI* regTree;
		Match matchs;

};
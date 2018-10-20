#pragma once
#include "Match.h"
#include "NodeI.h"
#include "Engine.h"
#include "Match.h"
/**
 * @brief
 * Class use to store a regex and apply it on string
 */
class Regex
{
	public:
		Regex(std::string s,int F=NONE);
		Match matchString(const std::string &s);
		Regex& SetPos(int i);
		int getLastPos() const;
	private:
		NodeI* regTree;
		Match matchs;
		int Flag;
		int lastPos;
		int ForcedPos;

};
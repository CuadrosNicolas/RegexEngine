#pragma once
#include "TGBody.h"
#include "Engine.h"
#include "LinkNode.h"
class TGReference;
class TGBuilder
{
	public:
		TGBuilder();
		TGReference Build(std::string s);
		TGReference Build(TGReference Reference);
		void SetMain(TGReference Reference);
		NodeI* access(int index);
		NodeI* accessEnd(int index);
		void Prepare(LinkNode* l,LinkNode* begin=nullptr);
		Match parse(std::string s);
		TGReference Valid();
	private:
		TGReference* mainRef;
		std::vector<TGBody*> Register;
		NodeI* tempBegin;
		LinkNode* tempBody;
};
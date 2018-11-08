#include "TGBuilder.h"
#include "TGReference.h"
TGBuilder::TGBuilder()
{
	tempBody = nullptr;
}

TGReference TGBuilder::Build(std::string s)
{
	TreeCouple *temp = Engine::GenBody(s);
	TGBody* body = new TGBody();
	body->setBegin(temp->begin);
	body->setEnd(temp->end);
	TGReference temp_ref(this, Register.size());
	Register.push_back(body);
	return temp_ref;
}
TGReference TGBuilder::Build(TGReference Reference)
{
	return Valid();
}
NodeI* TGBuilder::access(int index)
{
	if(index<0)
		return tempBody;
	else
		return Register[index]->getBegin();
}
NodeI *TGBuilder::accessEnd(int index)
{
	if (index < 0)
		return tempBody;
	else
		return Register[index]->getEnd();
}

void TGBuilder::Prepare(LinkNode *l,LinkNode *begin)
{
	if(tempBody==nullptr)
	{
		tempBody = l;
		tempBegin = begin;
		tempBegin->setNext(tempBody);
	}
	else
	{
		tempBody->setNext(l);
		tempBody = l;
	}
}

TGReference TGBuilder::Valid()
{
	GroupBeginNode* temp = new GroupBeginNode();
	GroupEndNode* temp_end = new GroupEndNode(temp);
	temp->add(tempBegin);
	tempBody->setNext(temp_end);
	TGBody* body = new TGBody();
	body->setBegin(temp);
	body->setEnd(temp_end);
	tempBody = nullptr;
	tempBegin = nullptr;
	TGReference tempRef(this, Register.size());
	Register.push_back(body);
	return tempRef;
}

void TGBuilder::SetMain(TGReference Reference)
{
	GroupBeginNode *temp = new BeginNode();
	EndNode *temp_end = new EndNode();
	TGBody *body = new TGBody();
	body->setBegin(temp);
	body->setEnd(temp_end);
	temp->add(Register[Reference.getIndex()]->getBegin());
	Register[Reference.getIndex()]->getEnd()->setNext(temp_end);
	TGReference tempRef(this, Register.size());
	Register.push_back(body);
	mainRef = new TGReference(tempRef);
}
Match TGBuilder::parse(std::string s)
{
	int lastPos = 0;
	StringIterator it(s);

	while (it.end() == false)
	{
		it = access(mainRef->getIndex())->in(it);
		if (!it.isValid())
		{
			it = it + 1;
		}
		else
		{
			lastPos = it.pos;
		}

		it.reinit();
	}

	it.clean();
	return *(it.getMatch());
}
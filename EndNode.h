#pragma once
#include "NodeI.h"
/**
 * @brief
 * Node which will automaticaly match anything
 * This node correspond to the end of the regex (So the validation)
 */
class EndNode : public NodeI
{
  public:
		EndNode();
		bool test(char c);
		StringIterator in(StringIterator it);
};
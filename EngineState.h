#pragma once
#include "Engine.h"
/**
 * @brief
 *	Class representing a state of an engine.
 */
class EngineState
{
	public:
		/**
		 * @brief Construct a new Engine State object
		 *
		 * @param e parent engine
		 */
		EngineState(Engine *e);
		virtual ~EngineState();
		/**
		 * @brief
		 *	Parse a caracter to identify which action to do on the parent engine
		 * @param c Character to parse
		 * @return EngineState* Next state of the engine
		 */
	  	virtual EngineState *parse(char c);
		void addNode(NodeI* node);
		/**
		 * @brief
		 * Tell the engine to add a node to the current regex tree
		 */
	protected:
		Engine* parentEngine;
};
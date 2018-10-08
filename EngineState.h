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
		void addNode(NodeI* node);
	  virtual EngineState *parse(char c);
	protected:
		Engine* parentEngine;
};
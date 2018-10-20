#pragma once
/**
 * @brief
 * Enumération use to define the type of match
 */
enum RegFlag
{
	NONE = 0,
	STICKY = 1,//Allow the user to set the begining pos of the next match
	CASE_INSENSITIVE = 2,//The regex becomes case insensitive
	GLOBAL_SEARCH = 4,//The regex will search for matches till the end of the string
	MULTILINE = 8//Change the begin and end anchor to match \n

};
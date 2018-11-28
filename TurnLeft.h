#pragma once
#include "libraries.h"
#include "Snake.h"
#include "ICommand.h"
class TurnLeft: public ICommand
{
	Snake &snake;
	Body &body;
	Map &map;
public:
	TurnLeft(Snake &snake, Body body[], Map &map);
	void Execute();
};
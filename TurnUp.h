#pragma once
#include "libraries.h"
#include "Snake.h"
#include "ICommand.h"

class TurnUp:public ICommand
{
	Snake &snake;
	Body &body;
	Map &map;
public:
	TurnUp(Snake &snake, Body body[], Map &map);
	void Execute();
};
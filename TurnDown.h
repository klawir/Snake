#pragma once
#include "libraries.h"
#include "Snake.h"
#include "ICommand.h"

class TurnDown:public ICommand
{
	Snake &snake;
	Body &body;
	Map &map;
public:
	TurnDown(Snake &snake, Body body[], Map &map);
	void Execute();
};
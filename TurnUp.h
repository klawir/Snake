#pragma once
#include "libraries.h"
#include "Snake.h"
#include "ICommand.h"

class TurnUp:public ICommand
{
	Snake &snake;
public:
	TurnUp(Snake &snake);
	void Execute();
};
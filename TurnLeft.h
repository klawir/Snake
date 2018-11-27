#pragma once
#include "libraries.h"
#include "Snake.h"
#include "ICommand.h"
class TurnLeft
{
	Snake &snake;
public:
	TurnLeft(Snake &snake);
	void Execute();
};
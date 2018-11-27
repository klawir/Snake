#pragma once
#include "libraries.h"
#include "Snake.h"
#include "ICommand.h"
class TurnRight
{
public:
	Snake &snake;
public:
	TurnRight(Snake &snake);
	void Execute();
};
#pragma once
#include "libraries.h"
#include "Snake.h"
#include "ICommand.h"

class TurnDown:public ICommand
{
	Snake &snake;
public:
	TurnDown(Snake &snake);
	void Execute();
};
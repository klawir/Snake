#pragma once
#include "libraries.h"
#include "Snake.h"
#include "ICommand.h"
class TurnRight:public ICommand
{
public:
	Snake &snake;
	Body &body;
public:
	TurnRight(Snake &snake, Body body[]);
	void Execute();
};
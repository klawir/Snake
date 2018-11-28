#pragma once

#include "KeyBoard.h"
#include "Fruit.h"
#include "TurnRight.h"
#include "TurnLeft.h"
#include "TurnDown.h"
#include "TurnUp.h"

class GameManager
{
	KeyBoard *controll;
	Snake *snake;
	Map *map;
	Fruit *fruit;

	ICommand *turnRight;
	ICommand *turnLeft;
	ICommand *turnUp;
	ICommand *turnDown;

	enum { SIZEOFSNAKE = 200 };
public:
	GameManager(KeyBoard &controll, Snake &snake, Map &map, Fruit *fruit);
	void SnakeMove();
	void NewFruit();
	Body body[SIZEOFSNAKE];
};
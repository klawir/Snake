#pragma once

#include "KeyBoard.h"
#include "Fruit.h"

class GameManager
{
	KeyBoard *controll;
	Snake *snake;
	Map *map;
	Fruit *fruit;
	enum { SIZEOFSNAKE = 200 };
public:
	GameManager(KeyBoard &controll, Snake &snake, Map &map, Fruit *fruit);
	void SnakeMove();
	void NewFruit();
	Body body[SIZEOFSNAKE];
};
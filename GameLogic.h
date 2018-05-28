#pragma once

#include "Controll.h"
#include "Fruit.h"

class GameLogic :public Controll, public Fruit
{
public:
	GameLogic();
	void SnakeMoving(Controll &controll, Snake &snake, Map &map);
	bool FruitLogic(Snake &snake, Fruit *fruit, Controll controll);
	bool CheckCoordinates(int a, int b, string _operator);

	Body _body[SIZEOFSNAKE];
};


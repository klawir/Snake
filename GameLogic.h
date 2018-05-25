#pragma once
#include "Controll.h"
#include "Fruit.h"
class GameLogic :public Controll, public Fruit
{
	
public:
	GameLogic();
	~GameLogic();
	void SnakeMoving(Controll &controll, Snake &snake, Map &map);
	bool FruitLogic(Snake &snake, Fruit *fruit, Controll controll);
	Body _body[200];
};


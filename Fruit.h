#pragma once

#include "Map.h"
#include "Body.h"
#include "Snake.h"
#include "KeyBoard.h"

class Fruit:public Body
{
	string mark;
public:
	Fruit();
	Fruit(const Map *map);
	Fruit(const Map &map);
	string GetMark();
	int RandomCoordinates(int a);
	bool FruitLogic(Snake &snake, KeyBoard &controll);
	bool Eated(Snake &snake);
};
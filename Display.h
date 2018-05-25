#pragma once
#include "Snake.h"
#include "Controll.h"
#include "Fruit.h"
#include "GameLogic.h"
class Display:public Snake
{
public:
	Display();
	~Display();
	void Clear();
	void Show(Controll controll, Fruit *fruit, Snake snake, GameLogic &gamelogic, int points);
};
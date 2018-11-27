#pragma once

#include "Snake.h"
#include "KeyBoard.h"
#include "Fruit.h"
#include "GameManager.h"
#include "Map.h"

class View
{
	int index;
public:
	View();
	void Clear();
	void Render(KeyBoard &keyBoard, Fruit *fruit, Snake &snake, GameManager &gamelogic, Map &map);
};
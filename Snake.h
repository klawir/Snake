#pragma once
#include "Body.h"
#include "Map.h"
#include "KeyBoard.h"

class Snake
{
	enum { SIZEOFSNAKE = 200 };
	int begin;
	int end;
	KeyBoard *keyboard;
	Map *map;
	
public:
	Snake();
	Snake(Map map, KeyBoard keyboard);
	int GetSnakeBodyXPos();
	int GetSnakeBodyYPos();
	Body snakeBody[SIZEOFSNAKE];
	int Begin();
	int End();

	void IncreaseHeadYCoordinates();
	void IncreaseHeadXCoordinates(); 

	void DecreaseHeadYCoordinates();
	void DecreaseHeadXCoordinates();

	void IncreaseEnd();
	bool AteSomething();

	void BasicBodyMove(Body body[]);

	void IncreaseSnakeBody(KeyBoard &keyboard);

	bool Suicide();

};
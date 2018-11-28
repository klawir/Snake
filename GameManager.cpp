#include "GameManager.h"

GameManager::GameManager(KeyBoard &controll, Snake &snake, Map &map, Fruit *fruit)
{
	this->controll = new KeyBoard();
	this->snake = new Snake();
	this->map = new Map();

	this->controll = &controll;
	this->snake = &snake;
	this->map = &map;
	this->fruit = fruit;
	turnRight = new TurnRight(snake, body);
	turnLeft = new TurnLeft(snake, body, map);
	turnDown = new TurnDown(snake, body, map);
	turnUp = new TurnUp(snake, body, map);
}
void GameManager::SnakeMove()
{
	if (controll->Getright())
		turnRight->Execute();
	else if (controll->Getleft())
		turnLeft->Execute();
	else if (controll->Getup())
		turnUp->Execute();
	else if (controll->Getdown())
		turnDown->Execute();
	if (snake->AteSomething())
	{
		for (int a = 1; a <= snake->End(); a++)
		{
			snake->snakeBody[a].SetY(body[a].GetY());
			snake->snakeBody[a].SetX(body[a].GetX());
		}
	}
}
void GameManager::NewFruit()
{
	for (int a = 0; a<snake->End(); a++)
	{
		for (int b = 0; b<snake->End(); b++)
		{
			fruit = new Fruit(map);
			if (fruit->GetY() != snake->snakeBody[a].GetY()
				&& fruit->GetX() != snake->snakeBody[b].GetX())
				break;
		}
	}
}
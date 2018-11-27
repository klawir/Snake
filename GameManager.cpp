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
}
void GameManager::SnakeMove()
{
	if (controll->Getright())
	{
		if (snake->AteSomething())
		{
			snake->BasicBodyMove(body);
			if (snake->snakeBody[snake->End()].GetX()== map->GetWidth() - 1)
				snake->snakeBody[snake->End()].SetX(0);
			else if (snake->snakeBody[snake->Begin()].GetX()==map->GetWidth() - 1)
				snake->snakeBody[snake->Begin()].SetX(0);
		}
		else if (snake->snakeBody[snake->Begin()].GetX()== map->GetWidth() - 1)
			snake->snakeBody[snake->Begin()].SetX(0);
		snake->IncreaseHeadXCoordinates();
	}

	else if (controll->Getup())
	{
		if (snake->AteSomething())
		{
			snake->BasicBodyMove(body);
			for (int a = 1; a < snake->End(); a++)
			{
				snake->snakeBody[a].DecreaseYCoordinates();
				if (snake->snakeBody[a].GetY() == 0)
					snake->snakeBody[a].SetX(map->GetHeight() - 1);
			}
			if (snake->snakeBody[snake->End()].GetY()==0)
				snake->snakeBody[snake->End()].SetY(map->GetHeight() - 1);
			else if (snake->snakeBody[snake->Begin()].GetY()== 0)
				snake->snakeBody[snake->Begin()].SetY(map->GetHeight() - 1);
		}
		else if (snake->snakeBody[snake->Begin()].GetY()== 0)
			snake->snakeBody[snake->Begin()].SetY(map->GetHeight() - 1);
		snake->DecreaseHeadYCoordinates();
	}

	else if (controll->Getdown())
	{
		if (snake->AteSomething())
		{
			snake->BasicBodyMove(body);
			for (int a = 1; a < snake->End(); a++)
			{
				snake->snakeBody[a].IncreaseYCoordinates();
				if (snake->snakeBody[a].GetY() == map->GetHeight() - 1)
					snake->snakeBody[a].SetX(0);
			}
			if (snake->snakeBody[snake->End()].GetY()== map->GetHeight() - 1)
				snake->snakeBody[snake->End()].SetY(0);
			else if (snake->snakeBody[snake->Begin()].GetY()== map->GetHeight() - 1)
				snake->snakeBody[snake->Begin()].SetY(0);
		}
		else if (snake->snakeBody[snake->Begin()].GetY()== map->GetHeight() - 1)
			snake->snakeBody[snake->Begin()].SetY(0);
		snake->IncreaseHeadYCoordinates();
	}

	else if (controll->Getleft())
	{
		if (snake->AteSomething())
		{
			snake->BasicBodyMove(body);
			for (int a = 1; a < snake->End(); a++)
			{
				snake->snakeBody[a].DecreaseHeadXCoordinates();
				if (snake->snakeBody[a].GetX() == 0)
					snake->snakeBody[a].SetX(map->GetWidth() - 1);
			}
			if (snake->snakeBody[snake->End()].GetX()== 0)
				snake->snakeBody[snake->End()].SetX(map->GetWidth() - 1);
			else if (snake->snakeBody[snake->Begin()].GetX()== 0)
				snake->snakeBody[snake->Begin()].SetX(map->GetWidth() - 1);
		}
		else if (snake->snakeBody[snake->Begin()].GetX()== 0)
			snake->snakeBody[snake->Begin()].SetX(map->GetWidth() - 1);
		snake->DecreaseHeadXCoordinates();
	} 
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
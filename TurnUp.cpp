#include "TurnUp.h"



TurnUp::TurnUp(Snake &snake, Body body[], Map &map) :snake(snake), body(*body), map(map)
{
}
void TurnUp::Execute()
{
	if (snake.AteSomething())
	{
		snake.BasicBodyMove(&body);
		snake.DecreaseYCoorditanes();
		if (snake.snakeBody[snake.End()].GetY() == 0)
			snake.snakeBody[snake.End()].SetY(map.GetHeight() - 1);
		else if (snake.snakeBody[snake.Begin()].GetY() == 0)
			snake.snakeBody[snake.Begin()].SetY(map.GetHeight() - 1);
	}
	else if (snake.snakeBody[snake.Begin()].GetY() == 0)
		snake.snakeBody[snake.Begin()].SetY(map.GetHeight() - 1);
	snake.DecreaseHeadYCoordinates();
}
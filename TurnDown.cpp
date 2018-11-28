#include "TurnDown.h"



TurnDown::TurnDown(Snake &snake, Body body[], Map &map) :snake(snake), body(*body), map(map)
{

}


void TurnDown::Execute()
{
	if (snake.AteSomething())
	{
		snake.BasicBodyMove(&body);
		for (int a = 1; a < snake.End(); a++)
		{
			snake.snakeBody[a].IncreaseYCoordinates();
			if (snake.snakeBody[a].GetY() == map.GetHeight() - 1)
				snake.snakeBody[a].SetX(0);
		}
		if (snake.snakeBody[snake.End()].GetY() == map.GetHeight() - 1)
			snake.snakeBody[snake.End()].SetY(0);
		else if (snake.snakeBody[snake.Begin()].GetY() == map.GetHeight() - 1)
			snake.snakeBody[snake.Begin()].SetY(0);
	}
	else if (snake.snakeBody[snake.Begin()].GetY() == map.GetHeight() - 1)
		snake.snakeBody[snake.Begin()].SetY(0);
	snake.IncreaseHeadYCoordinates();
}
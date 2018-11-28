#include "TurnLeft.h"



TurnLeft::TurnLeft(Snake &snake, Body body[], Map &map) :snake(snake), body(*body), map(map)
{

}
void TurnLeft::Execute()
{
	if (snake.AteSomething())
	{
		snake.BasicBodyMove(&body);
		snake.DecreaseXCoorditanes();
		snake.BodyOnLeftXEdgeOfMap();
	}
	else if (snake.BeginOnLefttXEdgeOfMap())
		snake.snakeBody[snake.Begin()].SetX(map.GetWidth() - 1);
	snake.DecreaseHeadXCoordinates();
}
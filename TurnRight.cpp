#include "TurnRight.h"



TurnRight::TurnRight(Snake &snake, Body body[]):snake(snake), body(*body)
{

}
void TurnRight::Execute()
{
	if (snake.AteSomething())
	{
		snake.BasicBodyMove(&body);
		if (snake.EndOnRightXEdge())
			snake.BodyEndResetX();
		else if (snake.BeginOnRightXEdgeOfMap())
			snake.BodyBeginResetX();
	}
	else if (snake.BeginOnRightXEdgeOfMap())
		snake.BodyBeginResetX();
	snake.IncreaseHeadXCoordinates();
}
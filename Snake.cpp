
#include "Snake.h"
#define MINIMAL_VALUE_PARTS_OF_SNAKE_TO_COLLISION 4
Snake::Snake()
{

}
Snake::Snake(Map map, KeyBoard keyboard)
{
	begin = 0;
	end = begin;
	snakeBody[SIZEOFSNAKE];
	snakeBody[0].SetX(map.GetWidth()/2);
	snakeBody[0].SetY(map.GetHeight()/2);
	this->keyboard = new KeyBoard;
	this->keyboard = &keyboard;
	this->map = new Map;
	this->map = &map;
}
int Snake::GetSnakeBodyXPos()
{
	return snakeBody[begin].GetX();
}
int Snake::GetSnakeBodyYPos()
{
	return snakeBody[begin].GetY();
}
int Snake::Begin()
{
	return begin;
}
int Snake::End()
{
	return end;
}
void Snake::IncreaseHeadYCoordinates()
{
	snakeBody[begin].IncreaseYCoordinates();
}
void Snake::IncreaseHeadXCoordinates()
{
	snakeBody[begin].IncreaseXCoordinates();
}
void Snake::DecreaseHeadYCoordinates()
{
	snakeBody[begin].DecreaseYCoordinates();
}
void Snake::DecreaseHeadXCoordinates()
{
	snakeBody[begin].DecreaseHeadXCoordinates();
}
void Snake::IncreaseEnd()
{
	end++;
}
bool Snake::AteSomething()
{
	return end > begin;
}
void Snake::BasicBodyMove(Body body[])
{
	for (int a = 1; a <= end; a++)
	{
		body[a].SetY(snakeBody[a - 1].GetY());
		body[a].SetX(snakeBody[a - 1].GetX());
	}
}
void Snake::IncreaseSnakeBody(KeyBoard &keyboard)
{
	if (keyboard.Getright())
	{
		snakeBody[end].SetY(snakeBody[end - 1].GetY());
		snakeBody[end].SetX(snakeBody[end - 1].GetX() - 1);
	}
	else if (keyboard.Getleft())
	{
		snakeBody[end].SetY(snakeBody[end - 1].GetY());
		snakeBody[end].SetX(snakeBody[end - 1].GetX() + 1);
	}
	else if (keyboard.Getup())
	{
		snakeBody[end].SetY(snakeBody[end - 1].GetY()+1);
		snakeBody[end].SetX(snakeBody[end - 1].GetX());
	}
	else if (keyboard.Getdown())
	{
		snakeBody[end].SetY(snakeBody[end - 1].GetY()-1);
		snakeBody[end].SetX(snakeBody[end - 1].GetX());
	}
}
bool Snake::Suicide()
{
	for (int a = MINIMAL_VALUE_PARTS_OF_SNAKE_TO_COLLISION; a <= end; a++)
	{
		if (snakeBody[begin].GetY() == snakeBody[a].GetY()
			&& snakeBody[begin].GetX() == snakeBody[a].GetX())
			return true;
	}
}
bool Snake::EndOnRightXEdge()
{
	return snakeBody[end].GetX() == map->GetWidth() - 1;
}
void Snake::BodyEndResetX()
{
	snakeBody[end].SetX(0);
}
void Snake::BodyBeginResetX()
{
	snakeBody[begin].SetX(0); 
}
bool Snake::BeginOnRightXEdgeOfMap()
{
	return snakeBody[begin].GetX() == map->GetWidth() - 1;
}
bool Snake::EndOnLeftXEdgeOfMap()
{
	return snakeBody[end].GetX() == 0;
}
bool Snake::BeginOnLefttXEdgeOfMap()
{
	return snakeBody[begin].GetX() == 0;
}
void Snake::BodyOnLeftXEdgeOfMap()
{
	if (EndOnLeftXEdgeOfMap())
		snakeBody[end].SetX(map->GetWidth() - 1);
	else if (BeginOnLefttXEdgeOfMap())
		snakeBody[begin].SetX(map->GetWidth() - 1);
}
void Snake::DecreaseXCoorditanes()
{
	for (int a = 1; a < end; a++)
	{
		snakeBody[a].DecreaseHeadXCoordinates();
		if (snakeBody[a].GetX() == 0)
			snakeBody[a].SetX(map->GetWidth() - 1);
	}
}
void Snake::DecreaseYCoorditanes()
{
	for (int a = 1; a < end; a++)
	{
		snakeBody[a].DecreaseYCoordinates();
		if (snakeBody[a].GetY() == 0)
			snakeBody[a].SetX(map->GetHeight() - 1);
	}
}

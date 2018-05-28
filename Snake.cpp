#pragma once
#include "Snake.h"

Snake::Snake()
{
	begin = 0;
	end = begin;
	for (int a=1; a <sizeOfSnake; a++)
		body[a].x = body[a].y = 0;
	body[0].x = Map::GetWidth() / 2;
	body[0].y = Map::GetHeight() / 2;
}
Snake::~Snake()
{
}
void Snake::SetYBody(int a)
{
	body[begin].y += a;
	//if (end > begin)
	//	body[end].y += a;
}
void Snake::SetXBody(int a)
{
	body[begin].x += a;
	//if (end > begin)
	//	body[end].x += a;
}
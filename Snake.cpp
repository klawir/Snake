#pragma once
#include "Snake.h"

Snake::Snake()
{
	begin = 0;
	end = begin;
	for (int a=1; a <SIZEOFSNAKE; a++)
		body[a].x = body[a].y = 0;
	body[0].x = Map::GetWidth() / 2;
	body[0].y = Map::GetHeight() / 2;
}

void Snake::SetYCoordinates(int a)
{
	body[begin].y += a;
}
void Snake::SetXCoordinates(int a)
{
	body[begin].x += a;
}
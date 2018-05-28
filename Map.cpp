#pragma once
#include "Map.h"

Map::Map()
{
	for (int a = 0; a < HEIGHT; a++)
	{
		for (int b = 0; b < WIDTH; b++)
			map[a][b] = " ";
	}
}

int Map::GetWidth()const
{
	return WIDTH;
}
int Map::GetHeight()const
{
	return HEIGHT;
}
#pragma once
#include "Map.h"

Map::Map()
{
	for (int a = 0; a < height; a++)
	{
		for (int b = 0; b < width; b++)
			map[a][b] = " ";
	}
}

Map::~Map()
{

}
int Map::GetWidth()const
{
	return width;
}
int Map::GetHeight()const
{
	return height;
}
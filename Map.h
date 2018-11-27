#pragma once

#include "libraries.h"

class Map
{
	enum { HEIGHT = 15, WIDTH = 30 };
public:
	string map[HEIGHT][WIDTH];
	Map();
	int GetWidth()const;
	int GetHeight()const;
};
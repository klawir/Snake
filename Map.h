#pragma once
#include "libraries.h"
class Map
{
	
public:
	enum { height = 15, width = 30 };
	string map[height][width];
	Map();
	~Map();
	int GetWidth()const;
	int GetHeight()const;
};


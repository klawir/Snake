#pragma once
#include "Map.h"
#include <fstream>

class Snake:public Map
{
public:
	enum { SIZEOFSNAKE = 200 };
	struct Body
	{
		int x;
		int y;
	};
	Snake();
	int begin;
	int end;
	Body body[SIZEOFSNAKE];
	void SetYCoordinates(int a);
	void SetXCoordinates(int a);
};
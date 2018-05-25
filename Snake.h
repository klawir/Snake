#pragma once
#include "Map.h"
#include <fstream>
using std::ofstream;
class Snake:public Map
{
	enum { sizeOfSnake = 200 };
public:
	struct Body
	{
		int x;
		int y;
	};
	Snake();
	~Snake();
	int begin;
	int end;
	Body body[sizeOfSnake];
	void SetYBody(int a);
	void SetXBody(int a);
};
#pragma once

#include "Snake.h"

class Fruit:public Snake
{
	int y;
	int x;
	string mark;
public:
	Fruit();
	int GetYCoordinates();
	int GetXCoordinates();
	void SetYCoordinates(int a);
	void SetXCoordinates(int a);
	string GetMark();
	int RandomCoordinates(int a);
};
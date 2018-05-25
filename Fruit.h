#pragma once
#include "Snake.h"
class Fruit:public Snake
{
	int y;
	int x;
	string mark;
public:
	Fruit();
	~Fruit();
	int GetY();
	int GetX();
	void SetY(int a);
	void SetX(int a);
	string GetMark();
};
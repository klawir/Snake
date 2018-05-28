#pragma once
#include "Snake.h"

class Controll:public Snake
{
	bool left, right, up, down;
public:
	Controll();
	~Controll();
	void Keyboard();

	bool Getleft();
	bool Getright();
	bool Getup();
	bool Getdown();
};


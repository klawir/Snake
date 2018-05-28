#pragma once


#include "Snake.h"

class Controll:public Snake
{
	bool left, right, up, down;
	void Turnig(bool left, bool right, bool up, bool down);
public:
	Controll();
	void Keyboard();

	bool Getleft();
	bool Getright();
	bool Getup();
	bool Getdown();
};


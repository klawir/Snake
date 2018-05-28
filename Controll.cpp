#include "Controll.h"

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

Controll::Controll()
{
	left = false;
	right = false;
	up = false;
	down = false;
	right = true;
}
void Controll::Turnig(bool left, bool right, bool up, bool down)
{
	this->left = left;
	this->right = right;
	this->down = down;
	this->up = up;
}

void Controll::Keyboard()
{
	int key;
	if (_kbhit())
	{
		key = _getch();
		switch (key)
		{
		case LEFT:
		{
			if (right) {}
			else
				Turnig(true, false, false, false);
		}break;
		case RIGHT:
		{
			if (left) {}
			else
				Turnig(false, true, false, false);
		}break;
		case UP:
		{
			if (down) {}
			else
				Turnig(false, false, true, false);
		}break;
		case DOWN:
		{
			if (up) {}
			else 
				Turnig(false, false, false, true);
		}break;
		default: {}
		}
	}
}
bool Controll::Getleft()
{
	return left;
}
bool Controll::Getright()
{
	return right;
}
bool Controll::Getup()
{
	return up;
}
bool Controll::Getdown()
{
	return down;
}
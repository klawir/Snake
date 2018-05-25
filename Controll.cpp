#include "Controll.h"
#define _left 75
#define _right 77
#define _up 72
#define _down 80

Controll::Controll()
{
	left=right=up=down=false;
	right = true;
}


Controll::~Controll()
{
}
void Controll::Keyboard()
{
	int key;
	if (_kbhit())
	{
		key = _getch();
		switch (key)
		{
		case _left:
		{
			if (right) {}
			else 
			{
				left = true;
				right = false;
				down = false;
				up = false;
			}
		}break;
		case _right:
		{
			if (left) {}
			else
			{
				right = true;
				left = false;
				down = false;
				up = false;
			}
		}break;
		case _up:
		{
			if (down) {}
			else
			{
				up = true;
				left = false;
				right = false;
				down = false;
			}
		}break;
		case _down:
		{
			if (up) {}
			else 
			{
				down = true;
				left = false;
				right = false;
				up = false;
			}
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
#include "KeyBoard.h"

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

KeyBoard::KeyBoard()
{
	left = false;
	up = false;
	down = false;
	right = true;
}

void KeyBoard::TurnLeft()
{
	left = true;
	right = false;
	down = false;
	up = false;
}
void KeyBoard::TurnRight()
{
	left = false;
	right = true;
	down = false;
	up = false;
}
void KeyBoard::TurnUp()
{
	left = false;
	right = false;
	down = false;
	up = true;
}
void KeyBoard::TurnDown()
{
	left = false;
	right = false;
	down = true;
	up = false;
}

void KeyBoard::Keyboard()
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
				TurnLeft();
		}break;
		case RIGHT:
		{
			if (left) {}
			else
				TurnRight();
		}break;
		case UP:
		{
			if (down) {}
			else
				TurnUp();
		}break;
		case DOWN:
		{
			if (up) {}
			else
				TurnDown();
		}break;
		default: {}
		}
	}
}
bool KeyBoard::Getleft()
{
	return left;
}
bool KeyBoard::Getright()
{
	return right;
}
bool KeyBoard::Getup()
{
	return up;
}
bool KeyBoard::Getdown()
{
	return down;
}
bool KeyBoard::AnyDirection()
{
	return up || down || left;
}
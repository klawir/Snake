#pragma once

#include "ICommand.h"

class KeyBoard
{
	bool left, right, up, down;
	void TurnLeft();
	void TurnRight();
	void TurnUp();
	void TurnDown();
public:
	KeyBoard();
	void Keyboard();

	bool Getleft();
	bool Getright();
	bool Getup();
	bool Getdown();
	bool AnyDirection();
};
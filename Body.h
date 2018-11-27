#pragma once

class Body
{
protected:
	int xPos;
	int yPos;
public:
	Body();
	int GetX();
	int GetY();
	void SetX(int);
	void SetY(int);
	void IncreaseYCoordinates();
	void IncreaseXCoordinates();
	void DecreaseYCoordinates();
	void DecreaseHeadXCoordinates();
};
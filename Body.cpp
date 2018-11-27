#include "Body.h"

Body::Body()
{
	xPos = 0;
	yPos = 0;
}
int Body::GetX()
{
	return xPos;
}
int Body::GetY()
{
	return yPos;
}
void Body::SetX(int value)
{
	xPos = value;
}
void Body::SetY(int value)
{
	yPos = value;
}
void Body::IncreaseYCoordinates()
{
	yPos++;
}
void Body::IncreaseXCoordinates()
{
	xPos++;
}
void Body::DecreaseYCoordinates()
{
	yPos--;
}
void Body::DecreaseHeadXCoordinates()
{
	xPos--;
}
#include "Fruit.h"



Fruit::Fruit()
{
	mark = "a";
	this->y=(RandomCoordinates((GetHeight()- 2) + 1));
	this->x=(RandomCoordinates((GetWidth() - 2) + 1));
}
int Fruit::GetYCoordinates()
{
	return y;
}
int Fruit::GetXCoordinates()
{
	return x;
}
string Fruit::GetMark()
{
	return mark;
}
void Fruit::SetYCoordinates(int a)
{
	y = a;
}
void Fruit::SetXCoordinates(int a)
{
	x = a;
}
int Fruit::RandomCoordinates(int a)
{
	return rand() % a;
}
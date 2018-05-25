#include "Fruit.h"



Fruit::Fruit()
{
	mark = "a";
}
Fruit::~Fruit()
{

}
int Fruit::GetY()
{
	return y;
}
int Fruit::GetX()
{
	return x;
}
string Fruit::GetMark()
{
	return mark;
}
void Fruit::SetY(int a)
{
	y = a;
}
void Fruit::SetX(int a)
{
	x = a;
}
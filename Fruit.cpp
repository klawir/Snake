#include "Fruit.h"

Fruit::Fruit() :Body()
{

}
Fruit::Fruit(const Map *map): Body()
{
	mark = "a";
	new Fruit();
	this->yPos = (RandomCoordinates((map->GetHeight() - 2) + 1));
	this->xPos = (RandomCoordinates((map->GetWidth() - 2) + 1));
}
Fruit::Fruit(const Map &map):Body()
{
	mark = "a";
	this->yPos=(RandomCoordinates((map.GetHeight()- 2) + 1));
	this->xPos=(RandomCoordinates((map.GetWidth() - 2) + 1));
}

string Fruit::GetMark()
{
	return mark;
}

int Fruit::RandomCoordinates(int a)
{
	return rand() % a;
}
bool Fruit::FruitLogic(Snake &snake, KeyBoard &controll)
{
	if (Eated(snake))
	{
		snake.IncreaseEnd();
		snake.IncreaseSnakeBody(controll);
		
		delete this;
		return true;
	}
	else return false;
}
bool Fruit::Eated(Snake &snake)
{
	return snake.snakeBody[snake.Begin()].GetY() == yPos 
		&& snake.snakeBody[snake.Begin()].GetX() == xPos;
}
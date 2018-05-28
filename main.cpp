#include "Snake.h"
#include "Display.h"
#include "Controll.h"
#include "Fruit.h"
#include "GameLogic.h"

#define MINIMAL_VALUE_PARTS_OF_SNAKE_TO_COLLISION 4

int loopCounter = 0;
int slowMotion;
int points;

int main()
{
	points = 0;
	srand(time(0));
	Map map;
	GameLogic gameLogic;
	Snake snake;
	Display display;
	slowMotion = 15;
	Controll controll;
	int a = 0, b = 0;
	Fruit *fruit= new Fruit;
	for (;;)
	{
		if (loopCounter%slowMotion == 0)
			gameLogic.SnakeMoving(controll, snake, map);
		if (gameLogic.FruitLogic(snake, fruit, controll)) 
		{
			a = b = 0;
			for(;;a++, b++)
			{
				fruit = new Fruit;
				if (gameLogic.CheckCoordinates(fruit->GetYCoordinates(), snake.body[a].y, "!=")
					&& gameLogic.CheckCoordinates(fruit->GetXCoordinates(), snake.body[b].x, "!="))
					break;
				else
					a = b = 0;
			}
			points++;
		}
		display.Clear();
		display.Show(controll, fruit, snake, gameLogic);
		controll.Keyboard();
		for (int a = MINIMAL_VALUE_PARTS_OF_SNAKE_TO_COLLISION;a <= snake.end;a++)
		{
			if (gameLogic.CheckCoordinates(snake.body[snake.begin].y, snake.body[a].y, "==")
				&& gameLogic.CheckCoordinates(snake.body[snake.begin].x, snake.body[a].x, "=="))
			{
				system("cls");
				return main();
			}
		}
		if (loopCounter > 99) 
			loopCounter = 0;
		loopCounter++;
		cout << points;
	}
	return 1;
}
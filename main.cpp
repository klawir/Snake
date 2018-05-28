#include "libraries.h"
#include "Map.h"
#include "Snake.h"
#include "Display.h"
#include "GeneralManager.h"
#include "Controll.h"
#include "Fruit.h"
#include "GameLogic.h"
using std::ofstream;
int main()
{
	points = 0;
	srand(time(0));
	Map map;
	Snake snake;
	Display display;
	slowMotion = 15;
	Controll controll;
	int y, x, a = 0, b = 0;
	y = rand() % (Map::height - 2) + 1;
	x = rand() % (Map::width - 2) + 1;
	Fruit *fruit= new Fruit;
	fruit->SetY(y);
	fruit->SetX(x);
	GameLogic gameLogic;
	for (;;)
	{
		if (loopCounter%slowMotion == 0)
			gameLogic.SnakeMoving(controll, snake, map);
		if (gameLogic.FruitLogic(snake, fruit, controll)) 
		{
			a = b = 0;
			for(;;a++, b++)
			{
				y = rand() % (Map::height - 2) + 1;
				x = rand() % (Map::width - 2) + 1;
				if (y != snake.body[a].y && x != snake.body[b].x)
				{
					fruit = new Fruit;
					fruit->SetY(y);
					fruit->SetX(x);
					break;
				}
				else
					a = b = 0;
			}
			points++;
		}
		display.Clear();
		display.Show(controll, fruit, snake, gameLogic, points);
		controll.Keyboard();
		for (int a = 4;a <= snake.end;a++)
		{
			if (snake.body[0].y == snake.body[a].y
				&&snake.body[0].x == snake.body[a].x)
				return main();
		}
		if (loopCounter > 99) 
			loopCounter = 0;
		loopCounter++;
		cout << points;
	}
}
#include "Snake.h"
#include "View.h"
#include "KeyBoard.h"
#include "Fruit.h"
#include "GameManager.h"

int main()
{
	int loopCounter = 0;
	int slowMotion = 15;
	int points = 0;

	srand(time(0));
	Map map;
	KeyBoard keyBoard;
	Snake snake(map, keyBoard);
	View view;
	Fruit *fruit= new Fruit(map);
	GameManager gameManager(keyBoard, snake, map, fruit);

	for (;;)
	{
		if (loopCounter%slowMotion == 0)
			gameManager.SnakeMove();
		else if (fruit->FruitLogic(snake, keyBoard))
		{
			gameManager.NewFruit();
			points++;
		}
		view.Clear();
		view.Render(keyBoard, fruit, snake, gameManager, map);
		keyBoard.Keyboard();
		if(snake.Suicide())
		{
			system("cls");
			return main();
		}
		else if (loopCounter > 99) 
			loopCounter = 0;
		loopCounter++;
		cout << points;
	}
	return 1;
}
#pragma once
#include "View.h"

View::View()
{
	index = 0;
}

void View::Clear()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void View::Render(KeyBoard &keyBoard, Fruit *fruit, Snake &snake, GameManager &gamelogic, Map &map)
{
	for (int a = 0; a< map.GetHeight(); a++)
	{
		for (int b = 0; b< map.GetWidth();b++)
		{
			if (keyBoard.Getright() && (snake.GetSnakeBodyYPos()== a)
				&& (snake.GetSnakeBodyXPos()== b))
				map.map[snake.GetSnakeBodyYPos()][snake.GetSnakeBodyXPos()] = "x";
			else if ((keyBoard.AnyDirection()) && (snake.GetSnakeBodyYPos()== a)
				&& (snake.GetSnakeBodyXPos()== b))
				map.map[snake.GetSnakeBodyYPos()][snake.GetSnakeBodyXPos()] = "x";
			else if (fruit->GetY()== a
				&& fruit->GetX()== b)
				map.map[fruit->GetY()][fruit->GetX()] = fruit->GetMark();
			else if (snake.End()> snake.Begin())
			{
				for (int q = 0; q <= snake.End(); q++)
				{
					if (snake.snakeBody[q].GetY()!= a
						&& (snake.snakeBody[q].GetX()!= b))
						map.map[snake.snakeBody[q].GetY()][snake.snakeBody[q].GetX()] = " ";
					else
						map.map[snake.snakeBody[q].GetY()][snake.snakeBody[q].GetX()] = "x";
				}
			}
			else if (snake.GetSnakeBodyYPos()!= a && snake.GetSnakeBodyXPos()!= b)
				map.map[snake.GetSnakeBodyYPos()][snake.GetSnakeBodyXPos()] = " ";
			else 
				map.map[a][b] = " ";
			cout << map.map[a][b];
			if (b == map.GetWidth() - 1)
				cout << endl;
			
		}
	}
}
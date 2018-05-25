#pragma once
#include "Display.h"
Display::Display()
{
}

Display::~Display()
{
}
void Display::Clear()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void Display::Show(Controll controll, Fruit *fruit, Snake snake, GameLogic &gamelogic, int points)
{
	for (int a = 0; a<height; a++)
	{
		for (int b = 0; b<width; b++)
		{
			if ((controll.Getright()) && snake.body[snake.begin].y == a && snake.body[snake.begin].x == b)
				map[snake.body[snake.begin].y][snake.body[snake.begin].x] = "x";
			else if ((controll.Getup() || controll.Getdown() || controll.Getleft()) && snake.body[snake.begin].y == a && snake.body[snake.begin].x == b)
				map[snake.body[snake.begin].y][snake.body[snake.begin].x] = "x";
			else if (fruit->GetY() == a && fruit->GetX() == b)
				map[fruit->GetY()][fruit->GetX()] = fruit->GetMark();
			else if (snake.end > snake.begin)
			{
				for (int q = 1;q <= snake.end;q++)
				{
					if(gamelogic._body[a].y >=0|| gamelogic._body[a].x >=0)
						map[gamelogic._body[a].y][gamelogic._body[a].x] = " ";
					map[snake.body[q].y][snake.body[q].x] = "x";
					gamelogic._body[a].y = snake.body[snake.end].y;
					gamelogic._body[a].x = snake.body[snake.end].x;
				}
			}
			else if (snake.body[snake.begin].y != a && snake.body[snake.begin].x != b)
				map[snake.body[snake.begin].y][snake.body[snake.begin].x] = " ";
			else 
				map[a][b] = " ";
			cout << map[a][b];
			if (b == width - 1)
				cout << endl;
		}
	}
}
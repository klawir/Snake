#pragma once
#include "Display.h"

Display::Display()
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
void Display::Show(Controll controll, Fruit *fruit, Snake snake, GameLogic &gamelogic)
{
	for (int a = 0; a<GetHeight(); a++)
	{
		for (int b = 0; b<GetWidth();b++)
		{
			if ((controll.Getright()) && gamelogic.CheckCoordinates(snake.body[snake.begin].y, a, "==")
				&& gamelogic.CheckCoordinates(snake.body[snake.begin].x, b, "=="))
				map[snake.body[snake.begin].y][snake.body[snake.begin].x] = "x";
			else if ((controll.Getup() || controll.Getdown() || controll.Getleft()) && gamelogic.CheckCoordinates(snake.body[snake.begin].y, a, "==")
				&& gamelogic.CheckCoordinates(snake.body[snake.begin].x, b, "=="))
				map[snake.body[snake.begin].y][snake.body[snake.begin].x] = "x";
			else if (gamelogic.CheckCoordinates(fruit->GetYCoordinates(), a, "==")
				&& gamelogic.CheckCoordinates(fruit->GetXCoordinates(), b, "=="))
				map[fruit->GetYCoordinates()][fruit->GetXCoordinates()] = fruit->GetMark();
			else if (gamelogic.CheckCoordinates(snake.end, snake.begin, ">"))
			{
				for (int q = 1;q <= snake.end;q++)
				{
					if ((gamelogic.CheckCoordinates(gamelogic._body[a].y, 0, ">=")) || (gamelogic.CheckCoordinates(gamelogic._body[a].x, 0, ">=")))
						map[gamelogic._body[a].y][gamelogic._body[a].x] = " ";
					map[snake.body[q].y][snake.body[q].x] = "x";
					gamelogic._body[a].y = snake.body[snake.end].y;
					gamelogic._body[a].x = snake.body[snake.end].x;
				}
			}
			else if (gamelogic.CheckCoordinates(snake.body[snake.begin].y, a, "!=") && gamelogic.CheckCoordinates(snake.body[snake.begin].x, b, "!="))
				map[snake.body[snake.begin].y][snake.body[snake.begin].x] = " ";
			else 
				map[a][b] = " ";
			cout << map[a][b];
			if (b == GetWidth() - 1)
				cout << endl;
		}
	}
}
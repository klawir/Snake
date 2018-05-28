#include "GameLogic.h"
#define TURN_RIGHT 1
#define TURN_UP -1
#define TURN_LEFT -1
#define TURN_DOWN 1

GameLogic::GameLogic()
{

}


void GameLogic::SnakeMoving(Controll &controll, Snake &snake, Map &map)
{
	if (controll.Getright())
	{
		if (CheckCoordinates(snake.end, snake.begin, ">"))
		{
			for (int a = 1; a <= snake.end; a++)
			{
				_body[a].y = snake.body[a - 1].y;
				_body[a].x = snake.body[a - 1].x;
			}
			if (CheckCoordinates(snake.body[snake.end].x, map.GetWidth() - 1, "=="))
				snake.body[snake.end].x = 0;
			else if (CheckCoordinates(snake.body[snake.begin].x, map.GetWidth() - 1, "=="))
				snake.body[snake.begin].x = 0;
		}
		else if (CheckCoordinates(snake.body[snake.begin].x, map.GetWidth() - 1, "=="))
			snake.body[snake.begin].x = 0;
		snake.SetXCoordinates(TURN_RIGHT);
	}

	else if (controll.Getup())
	{
		if (CheckCoordinates(snake.end, snake.begin, ">"))
		{
			for (int a = 1; a <= snake.end; a++)
			{
				_body[a].y = snake.body[a - 1].y;
				_body[a].x = snake.body[a - 1].x;
			}
			for (int a = 1; a < snake.end; a++)
			{
				snake.body[a].y--;
				if (snake.body[a].y == 0)
					snake.body[a].x = map.GetHeight() - 1;
			}
			if (CheckCoordinates(snake.body[snake.end].y, 0, "=="))
				snake.body[snake.end].y = map.GetHeight() - 1;
			else if (CheckCoordinates(snake.body[snake.begin].y, 0, "=="))
				snake.body[snake.begin].y = map.GetHeight() - 1;
		}
		else if (CheckCoordinates(snake.body[snake.begin].y, 0, "=="))
			snake.body[snake.begin].y = map.GetHeight() - 1;
		snake.SetYCoordinates(TURN_UP);
	}

	else if (controll.Getdown())
	{
		if (CheckCoordinates(snake.end, snake.begin, ">"))
		{
			for (int a = 1; a <= snake.end; a++)
			{
				_body[a].y = snake.body[a - 1].y;
				_body[a].x = snake.body[a - 1].x;
			}
			for (int a = 1; a < snake.end; a++)
			{
				snake.body[a].y++;
				if (snake.body[a].y == map.GetHeight() - 1)
					snake.body[a].x = 0;
			}
			if (CheckCoordinates(snake.body[snake.end].y, map.GetHeight() - 1, "=="))
				snake.body[snake.end].y = 0;
			else if (CheckCoordinates(snake.body[snake.begin].y, map.GetHeight() - 1, "=="))
				snake.body[snake.begin].y = 0;
		}
		else if (CheckCoordinates(snake.body[snake.begin].y, map.GetHeight() - 1, "=="))
			snake.body[snake.begin].y = 0;
		snake.SetYCoordinates(TURN_DOWN);
	}

	else if (controll.Getleft())
	{
		if (CheckCoordinates(snake.end, snake.begin, ">"))
		{
			for (int a = 1; a <= snake.end; a++)
			{
				_body[a].y = snake.body[a - 1].y;
				_body[a].x = snake.body[a - 1].x;
			}
			for (int a = 1; a < snake.end; a++)
			{
				snake.body[a].x--;
				if (snake.body[a].x == 0)
					snake.body[a].x = map.GetWidth() - 1;
			}
			if (CheckCoordinates(snake.body[snake.end].x, 0, "=="))
				snake.body[snake.end].x = map.GetWidth() - 1;
			else if (CheckCoordinates(snake.body[snake.begin].x, 0, "=="))
				snake.body[snake.begin].x = map.GetWidth() - 1;
		}
		else if (CheckCoordinates(snake.body[snake.begin].x, 0, "=="))
			snake.body[snake.begin].x = map.GetWidth() - 1;
		snake.SetXCoordinates(TURN_LEFT);
	} 
	if (GameLogic::CheckCoordinates(snake.end, snake.begin, ">"))
	{
		for (int a = 1; a <= snake.end; a++)
		{
			snake.body[a].y = _body[a].y;
			snake.body[a].x = _body[a].x;
		}
	}
}
bool GameLogic::FruitLogic(Snake &snake, Fruit *fruit, Controll controll)
{
	if (CheckCoordinates(snake.body[snake.begin].y, fruit->GetYCoordinates(), "==") && CheckCoordinates(snake.body[snake.begin].x, fruit->GetXCoordinates(), "=="))
	{
		snake.end++;
		if (controll.Getright())
		{
			snake.body[snake.end].y = snake.body[snake.end - 1].y;
			snake.body[snake.end].x = snake.body[snake.end - 1].x - 1;
		}
		else if (controll.Getleft())
		{
			snake.body[snake.end].y = snake.body[snake.end - 1].y;
			snake.body[snake.end].x = snake.body[snake.end - 1].x + 1;
		}
		else if (controll.Getup())
		{
			snake.body[snake.end].y = snake.body[snake.end - 1].y + 1;
			snake.body[snake.end].x = snake.body[snake.end - 1].x;
		}
		else if (controll.Getdown())
		{
			snake.body[snake.end].y = snake.body[snake.end - 1].y - 1;
			snake.body[snake.end].x = snake.body[snake.end - 1].x;
		}
		delete fruit;
		return true;
	}
	else return false;
}
bool GameLogic::CheckCoordinates(int a, int b, string _operator)
{
	if (_operator == ">")
		return a > b;
	else if (_operator == ">=")
		return a >= b;
	else if(_operator == "==")
		return a == b;
	else if(_operator=="!=")
		return a != b;
}

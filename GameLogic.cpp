#include "GameLogic.h"



GameLogic::GameLogic()
{

}


GameLogic::~GameLogic()
{
}
void GameLogic::SnakeMoving(Controll &controll, Snake &snake, Map &map)
{
	if (controll.Getright())
	{
		if (snake.end > snake.begin)
		{
			for (int a = 1; a <= snake.end; a++)
			{
				_body[a].y = snake.body[a - 1].y;
				_body[a].x = snake.body[a - 1].x;
			}
			if (snake.body[snake.end].x == map.width - 1)
				snake.body[snake.end].x = 0;
			else if (snake.body[snake.begin].x == map.width - 1)
				snake.body[snake.begin].x = 0;
		}
		else if (snake.body[snake.begin].x == map.width - 1)
			snake.body[snake.begin].x = 0;
		snake.SetXBody(1);
	}

	else if (controll.Getup())
	{
		if (snake.end > snake.begin)
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
					snake.body[a].x = map.height - 1;
			}
			if (snake.body[snake.end].y == 0)
				snake.body[snake.end].y = map.height - 1;
			else if (snake.body[snake.begin].y == 0)
				snake.body[snake.begin].y = map.height - 1;
		}
		else if (snake.body[snake.begin].y == 0)
			snake.body[snake.begin].y = map.height - 1;
		snake.SetYBody(-1);
	}

	else if (controll.Getdown())
	{
		if (snake.end > snake.begin)
		{
			for (int a = 1; a <= snake.end; a++)
			{
				_body[a].y = snake.body[a - 1].y;
				_body[a].x = snake.body[a - 1].x;
			}
			for (int a = 1; a < snake.end; a++)
			{
				snake.body[a].y++;
				if (snake.body[a].y == map.height - 1)
					snake.body[a].x = 0;
			}
			if (snake.body[snake.end].y == map.height - 1)
				snake.body[snake.end].y = 0;
			else if (snake.body[snake.begin].y == map.height - 1)
				snake.body[snake.begin].y = 0;
		}
		else if (snake.body[snake.begin].y == map.height - 1)
			snake.body[snake.begin].y = 0;
		snake.SetYBody(1);
	}

	else if (controll.Getleft())
	{
		if (snake.end > snake.begin)
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
					snake.body[a].x = map.width - 1;
			}
			if (snake.body[snake.end].x == 0)
				snake.body[snake.end].x = map.width - 1;
			else if (snake.body[snake.begin].x == 0)
				snake.body[snake.begin].x = map.width - 1;
		}
		else if (snake.body[snake.begin].x == 0)
			snake.body[snake.begin].x = map.width - 1;
		snake.SetXBody(-1);
	} 
	if (snake.end > snake.begin)
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
	if (snake.body[snake.begin].y == fruit->GetY() && snake.body[snake.begin].x == fruit->GetX())
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
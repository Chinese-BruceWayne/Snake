#pragma once


class Snake
{
public:
	friend void creat_food();
	friend bool isSnakePos(Snake *head, int x, int y);
	friend void creatSnake();
	
	int Get_x();
	int Get_y();
	Snake *Get_next();
	bool Bite_self();
	bool Can_not_crowall();
	bool Move();
private:
	int s_x;
	int s_y;
	Snake *next;
};

struct Obstacle
{
	int x;
	int y;
};

bool isSnakePos(Snake *head, int x, int y);
bool isObstractPos(Obstacle *o, int olen, int x, int y);
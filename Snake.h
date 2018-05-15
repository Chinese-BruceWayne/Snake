#pragma once
#include "basic.h"

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

extern Snake *head,*food;
extern Snake *q;
extern int condition;
extern int end_condition;
extern double speed;
extern double accel;
extern Obstacle *o;
extern int olen;


extern int score;
extern int add;
extern char SSymbol;
extern char FSymbol;
extern char WSymbol;
extern int width, length;

void creat_food();
bool isSnakePos(Snake *head, int x, int y);
bool isObstractPos(Obstacle *o, int olen, int x, int y);
void Die();
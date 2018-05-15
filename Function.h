#pragma once
#include "MapInfo.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
using namespace std;

#define UP 1
#define DOWN 2
#define LEFT 4
#define RIGHT 3

extern long long *Map;
extern Snake *head,*food;
extern Snake *q;
extern int condition;
extern int end_condition;
extern int score;
extern int add;
extern Obstacle *o;
extern int olen;
extern char SSymbol;
extern char FSymbol;
extern char WSymbol;
extern double speed;
extern double accel;
extern int width, length;

void Green_color();
void Red_color();
void Yellow_color();
void White_color();

void Set_location(int x, int y);
void SetSymbol();
void SetWL();
void SetSpeed();
void SetWindowsSize(int x,int y);
void PrintMap();
void SetMap();

void creat_food();
void pause();
void Die();
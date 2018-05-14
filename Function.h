#pragma once
#include"Snake.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
using namespace std;

#define UP 1
#define DOWN 2
#define LEFT 4
#define RIGHT 3

extern Snake *head,*food;
extern Snake *q;
extern int condition;
extern int end_condition;
extern int score;
extern int add;
extern Obstacle o[30];
extern char SSymbol;
extern char FSymbol;
extern char WSymbol;
extern double speed;

inline void Green_color()
{                               
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
		FOREGROUND_GREEN |
		FOREGROUND_INTENSITY);
}

inline void Red_color()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |
		FOREGROUND_INTENSITY);
}

inline void Yellow_color()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |
		FOREGROUND_GREEN |
		FOREGROUND_INTENSITY);
}

inline void White_color()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |
		FOREGROUND_GREEN |
		FOREGROUND_BLUE |
		FOREGROUND_INTENSITY);
}

void Set_location(int x, int y);
void Creat_obs(Obstacle o[], int n);
void SetSymbol();
void SetWL();
void SetSpeed();
void Initial();
void creat_food();
void creatMap();
void pause();
void Playing();
void Die();
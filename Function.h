
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

inline void Green_color();
inline void Red_color();
inline void Yellow_color();
inline void White_color();

void Set_location(int x, int y);
void Creat_obs(Obstacle o[], int n);
void Initial();
void creat_food();
void creatMap();
void pause();
void Start();
void Playing();
void Die();

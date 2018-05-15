#pragma once
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
using namespace std;

#define UP 1
#define DOWN 2
#define LEFT 4
#define RIGHT 3

void Green_color();
void Red_color();
void Yellow_color();
void White_color();
void Set_location(int x, int y);
void SetWindowsSize(int x,int y);
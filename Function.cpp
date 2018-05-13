#pragma once
#include"Function.h"

Snake *head, *food;
Snake *q;
int condition;
int end_condition = 0;
int score = 0, add = 1;
Obstacle o[30];
static const char SSymbol = 'O';
static const char FSymbol = 'o';
static const char WSymbol = 'H';

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

inline void White_color(){
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |
		FOREGROUND_GREEN |
		FOREGROUND_BLUE |
		FOREGROUND_INTENSITY);
}

void Set_location(int x, int y)
{
	COORD cd;
	HANDLE hOut;
	cd.X = x;
	cd.Y = y;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, cd);
}

void Creat_obs(Obstacle o[], int n)
{
	int a = 14, b = 24, c = 8, d = 40, e = 32, f = 10;
	for (int i = 0; i < 6; i++)
	{
		o[i].x = a;
		a += 2;
		o[i].y = c;
	}
	a = 15; b = 24; c = 8; d = 40; e = 32; f = 10;
	for (int i = 6; i < 15; i++)
	{
		o[i].x = b;
		o[i].y = c++;
	}
	a = 15; b = 23; c = 8; d = 40; e = 10; f = 17;
	for (int i = 15; i < 20; i++)
	{
		o[i].x = e;
		e += 2;
		o[i].y = f;
		f++;
	}
	a = 15; b = 23; c = 8; d = 40; e = 32; f = 13;
	for (int i = 20; i < 26; i++)
	{
		o[i].x = d;
		o[i].y = f;
		f++;
	}
	a = 15; b = 23; c = 8; d = 40; e = 44; f = 4;
	for (int i = 26; i < 30; i++)
	{
		o[i].x = e;
		e -= 2;
		o[i].y = f;
	}
	a = 15; b = 23; c = 8; d = 40; e = 32; f = 10;
	for (int i = 0; i < 30; i++)
	{
		Set_location(o[i].x, o[i].y);
		cout << WSymbol;
	}
}

void Initial()
{
	Snake *tail;
	int i;
	tail = new Snake;
	head = tail;
	head->s_x = 24;
	head->s_y = 5;
	head->next = NULL;
	for (i = 1; i <= 4; i++)
	{
		head = new Snake;
		head->next = tail;
		head->s_x = 24 + 2 * i;
		head->s_y = 5;
		tail = head;
	}
	while (tail->next != NULL)
	{
		Set_location(tail->s_x, tail->s_y);
		Green_color();
		cout << SSymbol;
		tail = tail->next;
	}
}

void creat_food()
{
	Snake *food_1;
	srand((unsigned)time(NULL));
	food_1 = new Snake;
	while ((food_1->s_x % 2) != 0)    
	{
		food_1->s_x = (rand() % 52) + 2;
	}
	food_1->s_y = (rand() % 24) + 1;
	q = head;
	while (q->next != NULL)
	{
		if (q->s_x == food_1->s_x && q->s_y == food_1->s_y) 
		{
			delete food_1;
			creat_food();
		}
		q = q->next;
	}
	for (int i = 0; i < 30; i++)
	{
		if (o[i].x == food_1->s_x && o[i].y == food_1->s_y)
		{
			delete food_1;
			creat_food();
		}
	}
	Set_location(food_1->s_x, food_1->s_y);
	food = food_1;
	Red_color();
	cout << FSymbol;
}

void creatMap()
{
	int i;
	for (i = 0; i<58; i += 2)
	{
		Set_location(i, 0);
		cout << WSymbol;
		Set_location(i, 26);
		cout << WSymbol;
	}
	Set_location(10, 0);
	cout << " ";
	Set_location(50, 26);
	cout << " ";
	for (i = 1; i<26; i++)
	{
		Set_location(0, i);
		cout << WSymbol;
		Set_location(56, i);
		cout << WSymbol;
	}
	Set_location(0, 20);
	cout << " ";
	Set_location(56, 6);
	cout << " ";
	Creat_obs(o, 30);
}

void pause()
{
	while (1)
	{
		Sleep(300);
		if (GetAsyncKeyState(VK_SPACE))
			break;                   
	}
}

void Start()
{
	system("mode con cols=100 lines=30");
	
	int i;
	for (i = 33; i<60; i += 2)
	{
		Set_location(i, 10);
		cout << WSymbol;
		Set_location(i, 14);
		cout << WSymbol;
	}
	for (i = 10; i<15; i++)
	{
		Set_location(33, i);
		cout << WSymbol;
		Set_location(61, i);
		cout << WSymbol;
	}
	Set_location(40, 12);
	cout << "Games--Greedy Snake" << endl;
	system("pause>nul");
	system("cls");
	Set_location(30, 12);
	cout << "control the snake using";
	Set_location(30, 13);
	cout<< "up, down, left, right" << endl;
	Set_location(30, 14);
	cout << "The snake can go through the barrier."<<endl;
	system("pause>nul");
	system("cls");
	creatMap();
	Initial();
	creat_food();
}
void Playing()
{
	Set_location(64, 15);
	Yellow_color();
	cout << "No wall crash. No self-crash." << endl;
	Set_location(64, 16);
	Yellow_color();
	cout << "control the snake using"<<endl;
	Set_location(64, 17);
	cout<<"up, down, left, right" << endl;
	Set_location(64, 18);
	Yellow_color();
	cout << "Snake can go through tunnel";
	Set_location(64, 19);
	cout<<" can't crash barrier."<<endl;
	Set_location(64, 20);
	Yellow_color();
	cout << "ESC:exit; space:pause" << endl;
	while (1)
	{
		Set_location(64, 10);
		Yellow_color();
		cout << "Score=" << score;
		Set_location(64, 11);
		Yellow_color();
		cout << "food: " << add << " score";
		if (GetAsyncKeyState(VK_UP) && condition != DOWN)
			condition = UP;
		else if (GetAsyncKeyState(VK_DOWN) && condition != UP)
			condition = DOWN;
		else if (GetAsyncKeyState(VK_LEFT) && condition != RIGHT)
			condition = LEFT;
		else if (GetAsyncKeyState(VK_RIGHT) && condition != LEFT)
			condition = RIGHT;
		else if (GetAsyncKeyState(VK_SPACE))
			pause();
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			end_condition = 3;
			break;
		}
		Sleep(200);
		head->Move();
	}
}

void Die()
{
	system("cls");
	Set_location(30, 12);
	if (end_condition == 1)
	{
		Yellow_color();
		cout << "Crash the wall!";
	}
	else if (end_condition == 2)
	{
		Yellow_color();
		cout << "Bite yourself!";
	}

	else if (end_condition == 3)
	{
		Yellow_color();
		cout << "End by player.";
	}
	else if (end_condition == 4)
	{
		Yellow_color();
		cout << "You crash the barrier!";
	}
	Set_location(30, 13);
	Yellow_color();
	cout << "Score: " << score << endl;
	system("pause>nul");
    exit(0);
    
}

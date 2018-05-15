#include "basic.h"

void Green_color()
{                               
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
		FOREGROUND_GREEN |
		FOREGROUND_INTENSITY);
}

void Red_color()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |
		FOREGROUND_INTENSITY);
}

void Yellow_color()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut,
		FOREGROUND_RED |
		FOREGROUND_GREEN |
		FOREGROUND_INTENSITY);
}

void White_color()
{
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

void SetWindowsSize(int x,int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT windowSize = {0, 0, x, y};
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}
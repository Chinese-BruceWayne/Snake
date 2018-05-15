#include"Function.h"

long long *Map = MapBit2;
Snake *head, *food;
Snake *q;
int condition;
int end_condition = 0;
int score = 0, add = 1;
Obstacle *o;
int olen;
char SSymbol = 'O';
char FSymbol = 'o';
char WSymbol = 'H';
double speed = 10;
double accel = 0.5;
int length = 26;
int width = 29;

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

void SetSymbol()
{
	system("cls");
	Set_location(30, 12);
	cout<<"Please chose a wall symbol:"<<WSymbol<<"-->";
	cin>>WSymbol;
	Set_location(30, 13);
	cout<<"Please chose a snake symbol:"<<SSymbol<<"-->";
	cin>>SSymbol;
	Set_location(30, 14);
	cout<<"Please chose a food symbol:"<<FSymbol<<"-->";
	cin>>FSymbol;
	Set_location(30, 15);
	cout<<"You have correctly set the symbol.";
	system("pause>nul");
	system("cls");
}

void SetWL()
{
	system("cls");
	Set_location(30, 12);
	cout<<"Current width:"<<width<<endl;
	Set_location(30, 13);
	cout<<"Please chose a width:";
	cin>>width;
	Set_location(30, 14);
	cout<<"Current length:"<<length<<endl;
	Set_location(30, 15);
	cout<<"Please chose a length:";
	cin>>length;
	Set_location(30, 16);
	cout<<"You have correctly set width/length.";
	system("pause>nul");
	system("cls");
}

void SetSpeed()
{
	system("cls");
	Set_location(30, 12);
	cout<<"Current speed:"<<speed<<endl;
	Set_location(30, 13);
	cout<<"Please chose a speed:";
	cin>>speed;
	Set_location(30, 14);
	cout<<"Current acceleration:"<<accel<<endl;
	Set_location(30, 15);
	cout<<"Please chose a accel:";
	cin>>accel;
	Set_location(30, 16);
	cout<<"You have correctly set speed and acceleration.";
	system("pause>nul");
	system("cls");
}

void SetWindowsSize(int x,int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT windowSize = {0, 0, x, y};
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}

void PrintMap()
{
	system("cls");
	SetWindowsSize((2*width-1)+50,length);
	Set_location(1, 1);
	cout<< "Current Map as show below:" <<endl;
	for(int i=0; i<width; ++i)
		for(int j=0; j<length; ++j)
			if(ReadMapPoint(Map,i,j))
			{
				Set_location(2*i, 2+j);
				cout<< WSymbol;
			}
	system("pause>nul");
	system("cls");
}

void SetMap()
{
	int pos = 0;
	system("cls");
	while(1)
	{
		cin.sync();
		if(GetAsyncKeyState(VK_RETURN)){}
		Sleep(200);
		system("cls");
		Set_location(30, 12);
		cout<<"Set Map0"<<endl;
		Set_location(30, 13);
		cout<<"Set Map1"<<endl;
		Set_location(30, 14);
		cout<<"Set Map2"<<endl;
		Set_location(30, 15);
		cout<<"confirm"<<endl;
		if (GetAsyncKeyState(VK_UP) && pos>0) pos--;
		else if (GetAsyncKeyState(VK_DOWN) && pos<3) pos++;
		else if (GetAsyncKeyState(VK_RETURN))
		{
			cin.ignore(1);
			if(pos == 0) Map = MapBit0, PrintMap();
			else if(pos == 1) Map = MapBit1, PrintMap();
			else if(pos == 2) Map = MapBit2, PrintMap();
			else if(pos == 3) break;
		}
		Set_location(60, (12+pos));
		cout<<"enter";
	}
	system("pause>nul");
	system("cls");
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

void creat_food()
{
	int x,y;
	do{
		do{
			x = (rand() % (width*2-7)) + 2;
		}while ((x % 2) != 0);
		y = (rand() % (length-2) ) + 1;
	}
	while( isSnakePos(head,x,y) || isObstractPos(o,olen,x,y) );

	Snake *food_1;
	food_1 = new Snake;
	food_1->s_x = x, food_1->s_y = y;
	Set_location(x, y);
	food = food_1;
	Red_color();
	cout << FSymbol;
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
		cout << "You crash the obstacle!";
	}
	Set_location(30, 13);
	Yellow_color();
	cout << "Score: " << score << endl;
	system("pause>nul");
	system("cls");
	Set_location(30, 12);
	cout<< "Restart?(y)";
	char ctrl;
	cin>>ctrl;
	if(ctrl != 'y') exit(0);
}

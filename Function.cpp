#include"Function.h"

Snake *head, *food;
Snake *q;
int condition;
int end_condition = 0;
int score = 0, add = 1;
Obstacle o[30];
char SSymbol = 'O';
char FSymbol = 'o';
char WSymbol = 'H';
double speed = 10;
int length = 26;
int width = 56;


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
	for (int i = 20; i < length; i++)
	{
		o[i].x = d;
		o[i].y = f;
		f++;
	}
	a = 15; b = 23; c = 8; d = 40; e = 44; f = 4;
	for (int i = length; i < 30; i++)
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
	cout<<"You have correctly set speed.";
	system("pause>nul");
	system("cls");
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
	food_1 = new Snake;
	do{
		food_1->s_x = (rand() % 52) + 1;
	}while ((food_1->s_x % 2) != 0);
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
	for (i = 0; i<width+2; i += 2)
	{
		Set_location(i, 0);
		cout << WSymbol;
		Set_location(i, length);
		cout << WSymbol;
	}
	Set_location(10, 0);
	cout << " ";
	Set_location(50, length);
	cout << " ";
	for (i = 1; i<length; i++)
	{
		Set_location(0, i);
		cout << WSymbol;
		Set_location(width, i);
		cout << WSymbol;
	}
	Set_location(0, 20);
	cout << " ";
	Set_location(width, 6);
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
	cout<<" can't crash obstacle."<<endl;
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
		Sleep(int(1000/speed));
		if( !head->Move() ) break;
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
		cout << "You crash the obstacle!";
	}
	Set_location(30, 13);
	Yellow_color();
	cout << "Score: " << score << endl;
	system("pause>nul");
	system("cls");
	Set_location(30, 12);
	cout<< "Resart?(y)";
	char ctrl;
	cin>>ctrl;
	if(ctrl != 'y') exit(0);
}

#include "Menu.h"

void Start()
{
	system("cls");
	SetWindowsSize(106,36);
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
	cout << "The snake can go through the obstacle."<<endl;
	system("pause>nul");
	system("cls");
	Menus();
	SetWindowsSize((2*width-1)+40,length+10);
	creatMap(Map);
	creatSnake();
}

void Menus()
{
	int pos = 0;
	while(1)
	{
		cin.sync();
		if(GetAsyncKeyState(VK_RETURN)){}
		Sleep(200);
		system("cls");
		Set_location(30, 12);
		cout<<"<Cassical games>"<<endl;
		Set_location(30, 13);
		cout<<"<Set character>"<<endl;
		Set_location(30, 14);
		cout<<"<Set Width/Length>"<<endl;
		Set_location(30, 15);
		cout<<"<Set Speed/Acceleration>"<<endl;
		Set_location(30, 16);
		cout<<"<Set Map>"<<endl;
		Set_location(30, 17);
		cout<<"<Exit Games>"<<endl;
		if (GetAsyncKeyState(VK_UP) && pos>0) pos--;
		else if (GetAsyncKeyState(VK_DOWN) && pos<5) pos++;
		else if (GetAsyncKeyState(VK_RETURN))
		{
			cin.ignore(1);
			if(pos == 0) break;
			else if(pos == 1) SetSymbol();
			else if(pos == 2) SetWL();
			else if(pos == 3) SetSpeed();
			else if(pos == 4) SetMap();
			else if(pos == 5) exit(0);
		}
		Set_location(60, (12+pos));
		cout<<"enter";
	}
	cin.ignore(1);
	system("cls");	
}

void creatSnake()
{
	Snake *tail;
	int i;
	tail = new Snake;
	head = tail;
	head->s_x = (((2*width-1)/2)|1)-1;
	head->s_y = length/2;
	head->next = NULL;
	for (i = 1; i <= 4; i++)
	{
		head = new Snake;
		head->next = tail;
		head->s_x = (((2*width-1)/2)|1)-1 + 2 * i;
		head->s_y = length/2;
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

void creatMap(long long *parmap)
{
	White_color();
	SetWindowsSize((2*width-1)+50,length);
	
	olen = ReadMap(&o,parmap,length,width);
	for(int i=0; i<olen; ++i)
	{
		Set_location(o[i].x, o[i].y);
		cout<< WSymbol;
		Set_location((2*width-1)+10, 22);
	}
}

void Playing()
{
	score = 0;
	creat_food();
	Set_location((2*width-1)+10, 15);
	Yellow_color();
	cout << "No wall crash. No self-crash." << endl;
	Set_location((2*width-1)+10, 16);
	Yellow_color();
	cout << "control the snake using"<<endl;
	Set_location((2*width-1)+10, 17);
	cout<<"up, down, left, right" << endl;
	Set_location((2*width-1)+10, 18);
	Yellow_color();
	cout << "Snake can go through tunnel";
	Set_location((2*width-1)+10, 19);
	cout<<" can't crash obstacle."<<endl;
	Set_location((2*width-1)+10, 22);
	Yellow_color();
	cout << "ESC:exit; space:pause" << endl;
	while (1)
	{
		Yellow_color();
		Set_location((2*width-1)+10, 9);
		double tmp = speed;
		for(int i=0; i<score; ++i) tmp += accel;
		cout << "Speed=" << tmp;
		Set_location((2*width-1)+10, 10);
		cout << "Score=" << score;
		Set_location((2*width-1)+10, 11);
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
		Sleep(int( 1000/(speed+score*accel) ));
		if( !head->Move() ) break;
	}
	delete []o;
}
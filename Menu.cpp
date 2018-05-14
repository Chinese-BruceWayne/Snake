#include "Menu.h"

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
	cout << "The snake can go through the obstacle."<<endl;
	system("pause>nul");
	system("cls");
	Menus();
}

void Menus()
{
	int pos = 0;
	while(1)
	{
		cin.sync();

		Set_location(30, 12);
		cout<<"<Cassical games>"<<endl;
		Set_location(30, 13);
		cout<<"<Set character>"<<endl;
		Set_location(30, 14);
		cout<<"<Set Width/Length>"<<endl;
		Set_location(30, 15);
		cout<<"<Set Speed>"<<endl;
		if (GetAsyncKeyState(VK_UP) && pos>0) pos--;
		else if (GetAsyncKeyState(VK_DOWN) && pos<3) pos++;
		else if (GetAsyncKeyState(VK_RETURN))
		{
			cin.ignore(1);
			if(pos == 0)
			{
				cin.ignore(1);
				system("cls");
				creatMap();
				Initial();
				creat_food();
				break;
			}
			else if(pos == 1)
			{		
				cin.ignore(1);
				SetSymbol();
			}
			else if(pos == 2)
			{
				cin.ignore(1);
				SetWL();
			}
			else if(pos == 3)
			{
				cin.ignore(1);
				SetSpeed();
			}
			if(GetAsyncKeyState(VK_RETURN)){}
		}
		Set_location(50, (12+pos));
		cout<<"enter";
		Sleep(200);
		system("cls");
	}
}
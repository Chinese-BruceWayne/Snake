#include"Function.h"

void SetSymbol()
{
	system("cls");
	cin.sync();
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
	cin.sync();
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
	cin.sync();
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

#include"Snake.h"

Snake *head, *food;
Snake *q;
int condition;
int end_condition = 0;
double speed = 10;
double accel = 0.5;
Obstacle *o;
int olen;

int score = 0, add = 1;
char SSymbol = 'O';
char FSymbol = 'o';
char WSymbol = 'H';
int length = 26;
int width = 29;

int Snake::Get_x()
{
	return s_x;
}

int Snake::Get_y()
{
	return s_y;
}

Snake *Snake::Get_next()
{
	return next;
}

bool Snake::Bite_self()
{
	Snake *self;
				

	self = head->Get_next();
	while (self->Get_next() != NULL)
	{
		if (self->Get_x() == head->Get_x() && self->Get_y() == head->Get_y())
			return 1;
		self = self->Get_next();
	}
	return 0;
}

bool Snake::Can_not_crowall()
{
	for (int i = 0; i < olen; i++)
	{
		if (head->s_x == o[i].x && head->s_y == o[i].y)
		{
			end_condition = 4;
			Die();
			return false;
		}
	}
	if ((head->s_x == 0 && head->s_y != 20) || (head->s_x == 56 && head->s_y != 6) || (head->s_y == 0 && head->s_x != 10) || (head->s_y == 26 && head->s_x != 50))
	{
		end_condition = 1;
		Die();
		return false;
	}
	return true;
}

bool Snake::Move()
{
	Snake *nexthead;
	nexthead = new Snake;
	if( !head->Can_not_crowall() ) return false;

	if (condition == UP)
	{
		nexthead->s_x = head->s_x;
		nexthead->s_y = head->s_y - 1;
		if (nexthead->s_x == food->s_x && nexthead->s_y == food->s_y)
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q != NULL)
			{              
				Set_location(q->s_x, q->s_y);
				Green_color();
				cout << SSymbol;
				q = q->next;
			}
			score += add;
			creat_food();
		}
		else
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next->next != NULL)
			{
				if (q->s_y < 0)
				{
					q->s_y += 27;
					q->s_x += 40;
				}
				Set_location(q->s_x, q->s_y);
				Green_color();
				cout << SSymbol;
				q = q->next;
			}
			Set_location(q->s_x, q->s_y);
			cout <<" ";
			delete q->next;
			q->next = NULL;
		}
	}
	
	if (condition == DOWN)
	{
		nexthead->s_x = head->s_x;
		nexthead->s_y = head->s_y + 1;
		if (nexthead->s_x == food->s_x && nexthead->s_y == food->s_y)
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q = NULL)
			{
				Set_location(q->s_x, q->s_y);
				Green_color();
				cout << SSymbol;
				q = q->next;
			}
			score += add;
			creat_food();
		}
		else
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next->next != NULL)
			{
				if (q->s_y > 26)
				{
					q->s_y -= 27;
					q->s_x -= 40;
				}
				Set_location(q->s_x, q->s_y);
				Green_color();
				cout << SSymbol;
				q = q->next;
			}
			Set_location(q->s_x, q->s_y);
			cout << " ";
			delete q->next;
			q->next = NULL;
		}
	}
	if (condition == LEFT)
	{
		nexthead->s_x = head->s_x - 2;
		nexthead->s_y = head->s_y;
		if (nexthead->s_x == food->s_x && nexthead->s_y == food->s_y)
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q = NULL)
			{
				Set_location(q->s_x, q->s_y);
				Green_color();
				cout << SSymbol;
				q = q->next;
			}
			score += add;
			creat_food();
		}
		else
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next->next != NULL)
			{
				if (q->s_x < 0)
				{
					q->s_x += 58;
					q->s_y -= 14;
				}
				Set_location(q->s_x, q->s_y);
				Green_color();
				cout << SSymbol;
				q = q->next;
			}
			Set_location(q->s_x, q->s_y);
			cout << " ";
			delete q->next;
			q->next = NULL;
		}
	}
	if (condition == RIGHT)
	{
		nexthead->s_x = head->s_x + 2;
		nexthead->s_y = head->s_y;
		if (nexthead->s_x == food->s_x && nexthead->s_y == food->s_y)
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q = NULL)
			{
				Set_location(q->s_x, q->s_y);
				Green_color();
				cout << SSymbol;
				q = q->next;
			}
			score += add;
			creat_food();
		}
		else
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next->next != NULL)
			{
				if (q->s_x > 56)
				{
					q->s_x -= 58;
					q->s_y += 14;
				}
				Set_location(q->s_x, q->s_y);
				Green_color();
				cout << SSymbol;
				q = q->next;
			}
			Set_location(q->s_x, q->s_y);
			cout << " ";
			delete q->next;
			q->next = NULL;
		}
	}
	if (Bite_self())
	{
		end_condition = 2;
		Die();
		return false;
	}
	return true;
}

bool isSnakePos(Snake *head, int x, int y)
{
	Snake *q = head;
	while (q->next != NULL)
	{
		if (q->s_x == x && q->s_y == y) 
			return true;
		q = q->next;
	}
	return false;
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

bool isObstractPos(Obstacle *o, int olen, int x, int y)
{
	for (int i = 0; i < olen; i++)
		if (o[i].x == x && o[i].y == y)
			return true;
	return false;
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

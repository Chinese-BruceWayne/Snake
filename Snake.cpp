#pragma once
#include"Function.h"

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

void Snake::Can_not_crowall()
{
	for (int i = 0; i < 30; i++)
	{
		if (head->s_x == o[i].x && head->s_y == o[i].y)
		{
			end_condition = 4;
			Die();
		}
	}
	if ((head->s_x == 0 && head->s_y != 20) || (head->s_x == 56 && head->s_y != 6) || (head->s_y == 0 && head->s_x != 10) || (head->s_y == 26 && head->s_x != 50))
	{
		end_condition = 1;
		Die();           

	}

}

static const char SSymbol = 'O';
void Snake::Move()
{
	Snake *nexthead;
	nexthead = new Snake;
	head->Can_not_crowall();

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
	}
}

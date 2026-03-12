#include <iostream>
#include <cstring>
using namespace std;

const int INIT = 100;
const int SPARE = 10;

typedef struct Stack
{
	char *bottom;
	char *top;
	char size;
} STK;

bool Init_Stk(STK &a)
{
	a.bottom = (char *) malloc (INIT * sizeof(char));
	if (!a.bottom)
		exit(-1);
	a.top = a.bottom;
	a.size = INIT;
}

bool Stk_Full(STK &a)
{
	if (a.bottom - a.top >= a.size)
		return true;
	return false;
}

bool Stk_Empty(STK &a)
{
	if (a.bottom == a.top)
		return true;
	return false;
}

bool Push_Stk(STK &a, char c)
{
	if (Stk_Full(a))
	{
		a.bottom = (char *) realloc (a.bottom, (a.size+SPARE) * sizeof(char));
		if (!a.bottom)
			exit(-1);
		a.top = a.bottom + a.size;
		a.size += SPARE;
	}
	else
		*(a.top++) = c;
	return true;
}

bool Pop_Stk(STK &a)
{
	if (!Stk_Empty(a))
	{
		a.top--;
		return true;
	}
	else
		return false;
}

bool Bkt_Matching(char a, char b)
{
	if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}') )
		return true;
	else
		return false;
}

void Ensure_Input(char s[])
{
	cout << "Is the string below the formula you entered?(y/n)\n";
	puts(s);

	char ensure;
	cin >> ensure;
	if (ensure == 'y')
		cout << "Brakets matching...\n";
	if (ensure == 'n')
		cout << "Please check the writing also program, and try again.\n";
	if (ensure != 'y' && ensure !='n')
	{
		cout << "Invalid Value, please input y or n";
		Ensure_Input(s);
	}
	return;
}

int main(void)
{
	STK bkt;
	Init_Stk(bkt);
	char s[INIT*SPARE];
	gets(s);
	Ensure_Input(s);

	if (s[0] == '\0')
	{
		cout << "Void input or input error, please try again.\n";
		return 0;
	}

	int i=0;
	bool flag = true;
	do
	{
		if (s[i]=='(' || s[i]=='[' || s[i]=='{')
			if (Push_Stk(bkt, s[i++]));
		if (s[i]==')' || s[i]==']' || s[i]=='}')
		{
			if (Bkt_Matching(*(bkt.top-1), s[i]))
				Pop_Stk(bkt);
			else
				flag = false;
		}
	}while (flag && s[++i] != '\0');

	if (flag)
		cout << "Brakets matching succeed, your formula is correct.\n";
	else
		cout << "Brakets matching failed, your formula exists mistake.\n";
	
	return 0;
}
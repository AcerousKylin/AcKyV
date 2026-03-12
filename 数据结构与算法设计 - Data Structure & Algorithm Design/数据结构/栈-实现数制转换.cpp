#include <iostream>
#include <cstring>
#include <cmath>
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

bool Pop_Stk(STK &a, char &elem)
{
	if (!Stk_Empty(a))
	{
        elem = *(a.top-1);
		a.top--;
		return true;
	}
	else
		return false;
}

int Stk_Len(STK &a)
{
    return (a.top-a.bottom);
}

bool BiToDe(STK &t)
{
    char b;
    scanf("%c", &b);
    while (b != '#')
    {
        if (b != '1' || b != '0')
            return false;
        Push_Stk(t, b);
        scanf("%c", &b);
    }
    getchar();

    int result=0, length=Stk_Len(t)-1;
    for (int i=0; i<length; i++)
    {
        char temp;
        Pop_Stk(t, temp);
        result += (temp-'0')*pow(2, i);
    }
    printf("Result is %d.\n", result);
    return true;
}

bool DeToBi(STK &t)
{
    int d;
    scanf("%d", &d);
    if (d < 0)
        return false;
    while (d != 0)
    {
        Push_Stk(t, d%2);
        //printf("Element been pushed is %d\n", d%2);
        d /= 2;
    }

    int length=Stk_Len(t);
    printf("Result is ");
    for (int i=0; i<length; i++)
    {
        char temp;
        Pop_Stk(t, temp);
        //printf("Element been popped is %d.\n", temp);
        printf("%d", temp);
    }
    printf(".\n");
    return true;
}

int main(void)
{
    STK num;
    Init_Stk(num);

    printf("This is a numeral transformer.\n");

    printf("What type of numeral system you gonna enter?\n");
    printf("d-decimalism | b-binary\n");
    char ns;
    scanf("%c", &ns);

    printf("Please enter your number, be aware that no space or enter.\n");
    if (ns == 'b')
        if (!BiToDe(num))
            printf("Invalid Value, please check your input and reboot.\n");
    if (ns == 'd')
        if (!DeToBi(num))
            printf("Negative value is not allowed, please reboot.\n");

    return 0;
}
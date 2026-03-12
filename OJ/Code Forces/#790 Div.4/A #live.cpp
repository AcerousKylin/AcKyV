#include<iostream>
using namespace std;

int main(void)
{
    int t;
    scanf("%d", &t);
    for (int i=0 ;i<t; i++)
    {   
        int number[6];
        int f=0, b=0;
        for (int i=0; i<3; i++)
        {
            scanf("%1d", &number[i]);
            f += number[i];
        }
        for (int i=0; i<3; i++)
        {
            scanf("%1d", &number[i]);
            b += number[i];
        }
        if (f==b)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
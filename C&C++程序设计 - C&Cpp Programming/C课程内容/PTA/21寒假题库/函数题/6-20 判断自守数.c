#include <stdio.h>

int IsAutomorphic(int x);

int main()
{
    int n;
    scanf("%d", &n);
    if (IsAutomorphic(n))
    {
        puts("Yes");
    }
    else
    {
        puts("No");
    }
    return 0;
}

/* 你提交的代码将被嵌在这里 */

int IsAutomorphic(int x)
{
    int ten=10, i, temp=0;
    if (x==0 && x==1)
        return 1;
    if (x<0)
        return 0;
    for(i=0; i<6; i++)
    {
        if (x/ten==0)
            break;
        ten *= 10;
    }
    temp = (x*x) % ten;
    if (temp==x)
        return 1;
    if (temp!=x)
        return 0;
}
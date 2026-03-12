//#142593斐波那契前20项
#include <stdio.h>
int fibo(int n)
{
    if (n==1||n==2)
        return 1;
    else
        return fibo(n-1)+fibo(n-2);
}
int main(void){
    int i, n; int a[20];
    for (i=0; i<20; i++)
        a[i] = fibo(i+1);
    for (i=0; i<20; i++)
    {
        if (i!=0 && i%5!=0)
            printf(" ");
        if (i%5==0 && i!=0)
            printf("\n");
        printf("%d", a[i]);
    }
    return 0;
}

//#142594三角形数 1 3 6 10 15 21 58 36 45 55 66 78 91...
#include<stdio.h>
int Triangle_Number(int n)
{
    if (n==1)
        return 1;
    else
        return n+Triangle_Number(n-1);
}
int main(void)
{
    int n[50]; int i;
    for (i=0; i<50; i++)
        n[i] = Triangle_Number(i+1);
    for (i=0; i<50; i++)
    {
        if (i!=0 && i%10!=0)
            printf(" ");
        if (i%10==0 && i!=0)
            printf("\n");
        printf("%d", n[i]);
    }
    return 0;
}
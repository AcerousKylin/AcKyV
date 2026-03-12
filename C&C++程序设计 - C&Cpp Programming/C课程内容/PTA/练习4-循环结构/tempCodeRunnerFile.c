#include<stdio.h>
int main(void)
{
    int n, i, o;
    char ch='A';
    scanf("%d", &n);
    for (i=n; i>=0; i--)
    {
        for (o=i-1; o>=0; o--)
        {
            putchar(ch);
            if (o>0) putchar(' ');
            if (o==0&&i!=0) putchar('\n');
            if (o==0&&i==0) return 0;
            ch++;
        }
    }
}
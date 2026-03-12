//最小公倍数
#include<stdio.h>
int main(void)
{
    int a, b, i;
    scanf("%d %d", &a, &b);
    if (a<b)
    {
        i = a; a = b; b = i;
    }
    for (i=a; i>=1; i++)
    {
        if (i%a==0&&i%b==0)
        {
            printf("%d", i);
            break;
        }
    }
    return 0;
}
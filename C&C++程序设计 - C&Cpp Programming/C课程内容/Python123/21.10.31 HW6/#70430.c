//斐波那契数列，输出小于某数的所有项
#include<stdio.h>
int main(void)
{
    int f1=1, f2=1, f3, n;
    scanf("%d", &n);
    printf("1 1 ");
    for (;;)
    {
            f3 = f1 + f2;
            if (f3>n) break;
            printf("%d ", f3);
            f1 = f2; f2 = f3;
    }
    return 0;
}

//写法2
int main(void)
{
    
}
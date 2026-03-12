//输入区间，检测7或11且非77的倍数
#include<stdio.h>
int main(void)
{
    int number, count;
    for (number=1; number<=1000; number++)
    {
        if ((number%7!=0||number%11!=0) && (number%7==0||number%11==0))
            count++;
    }
    printf("%d", count);
    return 0;
}
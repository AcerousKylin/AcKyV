//输入正整数时
#include<stdio.h>
int main(void)
{
    int number, count=0;
    scanf("%d", &number);
    while (number!=0)
    {
        count++;
        number /= 10;
    }
    printf("count=%d\n", count);
}

//输入自然数
#include<stdio.h>
int main(void)  
{
    int number, count=0;
    scanf("%d", &number);
    do
    {
        count++;
        number /= 10;
    }while (number!=0);
    printf("count=%d\n", count);
}
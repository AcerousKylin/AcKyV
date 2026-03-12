 //输入上限，穷举素数
#include<stdio.h>
int main(void)
{
    int count=0, number, multier;
    scanf("%d", &number);
    if (number>1)
    {
        for (multier=2; multier<number; multier++)
        {
            if (number%multier!=0) count++; 
        }
        if (number-count==2)
            printf("Y");
        else printf("N");
    }
    else printf("input error");
    return 0;
}

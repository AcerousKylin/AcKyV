#include<stdio.h>
int main(void)
{
    int a, b, c, d, sum;
    float sum1, avrg;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    sum = a+b+c+d;
    sum1 = sum;
    avrg = sum1/4;
    printf("Sum = %d; Average = %.1f", sum, avrg);
    return 0;
}
/*
    思路2：将“sum”定义为浮点数，不再定义“sum1”。
    删去8行，将10行“%d”换为“%.0f”。
    思路3：将“sum”定义为浮点数，不再定义“sum1”。
    删去8行，将10行“sum”改为“a+b+c+d”。
*/

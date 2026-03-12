/*函数e^x可以展开为幂级数1+x+x^2/2!+x^3/3!+⋯+x^k/k!+⋯
现给定一个实数x，要求利用此幂级数部分和求e ^x的近似值
求和一直继续到最后一项的绝对值小于0.00001*/
#include<stdio.h>
#include<math.h>
int main(void)
{
    int i;
    double x, sum=1, item=1;
    scanf("%lf", &x);
    for (i=1; fabs(item)>=0.00001; i++)
    {
        item *= x/i;
        sum += item;
    }
    printf("%.4lf", sum);
    return 0;
}
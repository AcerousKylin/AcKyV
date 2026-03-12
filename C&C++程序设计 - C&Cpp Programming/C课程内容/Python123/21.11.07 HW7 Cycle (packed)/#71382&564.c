//正确写法：
//#71382，题干在下面，下同。
#include<stdio.h>
int main(void)
{
    int i, j;
    for (i=0; i<=9; i++)
    {
        for (j=0; j<=15; j++)
        {
            if (3*i+2*j+1.0*(45-i-j)/2==45)
                printf("man=%d,woman=%d,child=%d\n", i, j, 45-i-j);
        }
    }
    return 0;
}

//#71564，题干在下面
#include<stdio.h>
int main(void)
{
    int i, j;
    for (i=1; i<=20; i++)
    {
        for (j=1: j<=33; j++)
        {
            if (5*i+3*j+1.0*(100-i-j)/3==100 && (100-i-j)>=1)
                printf("公鸡=%d只,母鸡=%d只,小鸡=%d只", i, j, 100-i-j);
        }
    }
    return 0;
}

//偷懒写法（偷懒了，但没完全偷）
//男人每人搬3块，女人每人搬2块，小孩2人搬一块
//有多少种搬法用45人正好搬45块砖？
#include<stdio.h>
int main(void)
{
    int f, m, c;
    for (f=0; f<=9; f+=3)
    {
        m = 15-f/3*5; c = 45-f-m;
        printf("man=%d,woman=%d,child=%d\n", f, m, c);
    }
    return 0;
}
//9行利用 2*m+(45-m-f)/2=45-f*3化简而来

//1公鸡5铜钱，1母鸡3铜钱，3小鸡1铜钱。
//现在有100铜钱，要买100鸡，每种鸡至少买一只，有几种买法
#include<stdio.h>
int main(void)
{
    int f, m, c;
    for (f=4; f<=12; f+=4)
    {
        m = 25-1.75*f; c = 100-f-m;
        printf("公鸡=%d只,母鸡=%d只,小鸡=%d只\n", f, m, c);
    }
    return 0;
}
//25行利用3*m+(100-f-m)/3=100-5*f化简而来
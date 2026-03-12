/*将一笔零钱换成5分、2分和1分的硬币
要求每种硬币至少有一枚，有几种不同的换法*/
#include<stdio.h>
int main(void)
{
    int x, f5, f2, f1=1, total, count=0, i, o;
    scanf("%d", &x);
    f5 = x / 5;
    for (f5=x/5; f5>=1; f5--)
    {
        for (f2=(x-f5*5)/2; f2>=1; f2--)
        {
            if((x-f5*5)%2==0&&x-f5*5-f2*2==0)
                f2--;
            while (f1>=1)
            {
                f1=x-f5*5-f2*2;
                total = f5 + f2 + f1;;
                printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", f5, f2, f1, total);
                count++;
                break;
            }
        }
    }
    printf("count = %d", count);
    return 0;
}
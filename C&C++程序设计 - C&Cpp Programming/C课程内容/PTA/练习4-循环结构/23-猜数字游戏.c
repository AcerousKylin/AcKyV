/*随机产生一个100以内的正整数，输入一个数进行猜测，对其与随机产生的被猜数进行比较
并提示大了（“Too big”），还是小了（“Too small”），相等表示猜到了。如果猜到，则结束程序。
程序还要求统计猜的次数，如果1次猜出该数，提示“Bingo!”；如果3次以内猜到该数，则提示“Lucky You!”
如果超过3次但是在N（>3）次以内（包括第N次）猜到该数，则提示“Good Guess!”
如果超过N次都没有猜到，则提示“Game Over”，并结束程序
如果在到达N次之前，用户输入了一个负数，也输出“Game Over”，并结束程序。*/
#include<math.h>
int main(void)
{
    int set, guess, n, i;
    scanf("%d %d", &set, &n);
    for(i=1; i<=n; i++)
    {
        scanf("%d", &guess);
        if (guess<0)
        {
            printf("Game Over");
            return 0;
        }
        else if (guess>set)
            printf("Too big\n");
        else if (guess<set)
            printf("Too small\n");
        else if (guess==set)
        {
            if (i==1)
            {
                printf("Bingo!");
                return 0;
            }
            else if (i==2||i==3)
            {
                printf("Lucky You!");
                return 0;
            }
            else if (i>3&&i<=n)
            {
                printf("Good Guess!");
                return 0;
            }
        }
        else;
    }
    printf("Game Over");
    return 0;
}
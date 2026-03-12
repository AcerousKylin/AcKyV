#include<stdio.h>
int main(void)
{
    unsigned long long n, result, backup;
    scanf("%llu", &n);
    result = backup = n * 2;

    int digits[2][20];
    int i, j, button=1;
    for (i=0; i<21; i++)
        digits[1][i] = -1;
    for (i=0; n!=0; i++)
    {
        digits[0][i] = n % 10;
        n /= 10;
    }
    for (j=0; j<i; j++)
    {
        int temp, k, flag=0;
        temp = backup % 10;
        for (k=0; k<i; k++)
        {
            if (digits[0][k]==temp && digits[1][k]==-1)
            {
                digits[1][k] = 1;
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            button = 0;
            break;
        }
        backup /= 10;
    }

    if (backup!=0)
        button = 0;
    for (j=0; j<i; j++)
    {
        if (digits[1][j]==-1)
        {
            button = 0;
            break;
        }
    }
    if (button)
        printf("Yes\n");
    else
        printf("No\n");

    int tail;
    tail = n % 100;
    n /= 100;
    n *= 2;
    tail *= 2;
    if (tail/100!=0)
    {
        n += tail/100;
        tail %= 100;
    }
    printf("%llu%d", result, tail);
    return 0;
}
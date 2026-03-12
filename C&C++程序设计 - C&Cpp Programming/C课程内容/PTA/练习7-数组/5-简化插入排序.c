#include<stdio.h>

// 补位排序法
int main(void)
{
    int n;
    scanf("%d", &n); n++;
    int number[n], i, j, temp;
    for (i=0; i<n; i++)
        scanf("%d", &number[i]);
    scanf("%d", number[n-1]);
    for (i=0; i<n; i++)
    {
        for (j=i+1; j<n; j++)
        {
            if (numbers[i]>numbers[j])
            {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    for (i=0; i<n; i++)
        printf("%d ", number[i]);
    return 0;
}

// 留空检测输出法（暂未实现）
/*
int main(void)
{
    int n;
    scanf("%d", &n); n = 2 * n + 1;
    int number[25]={0}, x, i;
    for (i=0; i<n; i++)
        number[i] = -1;
    for (i=1; i<n; i+=2)
        scanf("%d", &number[i]);
    scanf("%d", &x);
    for (i=1; i<n; i+=2)
    {
        if (i==1 && x<number[i])
        {
            number[0] = x;
            break;
        }
        if (i==n-2 && x>number[i])
        {
            number[i+1] = x;
            break;
        }
        if (x>number[i] && x<number[i+2])
        {
            number[i+1] = x;
            break;
        }
    }
    for (i=0; i<n; i++)
    {
        if (number[i]==-1)
            continue;
        else
            printf("%d ", number[i]);
    }
    return 0;
}
*/
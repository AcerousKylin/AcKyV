#include<stdio.h>
#include<stdlib.h>
#define N 10
int main(void)
{
    int a[N];
    int i, j, min, t; //min存储最小值的下标
    for (i=0; i<N; i++) //输入数据
        scanf("%d", &a[i])；
    for (j=0; j<N-1; j++)
    {
        min = j;
        for (i=j+1; i<N; i++)
            if (a[i]<a[min])
                min = i;
        if (min != j)
        {
            t = a[j];
            a[j] = a[min];
            a[min] = t;
        } //交换a[j]&a[min]
    }
    for (i=0; i<N; i++) //输出数据
        printf("%d", a[i]);
    return 0;
}
//写一个函数，使给定的一个二维数组（３×３）转置，即行列互换。
#include<stdio.h>
int main(void)
{
    int e[3][3]; int i=0, j=0;
    while(~scanf("%d", &e[i][j]))
    {
        j++;
        if (i+1%3==0)
            i++;
    }
    /*第二种输入：
    for (i=0; i<3; i++)
    {
        for (j=0; j<i; j++)
        {
            t=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=t;
        }
    }
    */
    printf("%d %d", e[0][0]+e[1][1]+e[2][2], e[0][2]+e[1][1]+e[2][0]);
    /*第二种输出：
    for (i=0; i<3; i++)
    {
        sum1+=a[i][i];
        sum2+=a[i][2-i]
    }
    */
    return 0;
}

//请自行脑补函数=)(并不是，在下面👇)
void Reverse(int a[][3]) //必须带列长度
{
    int i, j, t;
    for (i=0; i<3; i++)
    {
        for (j=0; j<i; j++)
        {
            t=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=t;
        }
    }
}
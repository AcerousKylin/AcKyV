//选择法从小到大排序
#include<stdio.h>
int main(void)
{
    int n[10];
    int i, j, a=0, t;
    for (i=0; i<10; i++)
        scanf("%d", &n[i]); //输入数组；
    for (i=0; i<10; i++)
     {
        for (j=i; j<10; j++)
        {
            if (n[j]<n[a]) //找出最小值，让其换到第一位
            {
                t=n[j]; n[j]=n[a]; n[a]=t; 
            }
        }
        a++; //寻找下一个最小值
    } //使用a作为临时的最低值下标，也就是最低值的“地址”
    for (i=0; i<10; i++)
        printf("%5d", n[i]);
    return 0;
}

//随机设定函数版
#include <stdio.h>
#include <stdlib.h>
void generate(int a[],int n)
{ //定义一个写有由时间为种子的随机数的数组
    int i;
    for(i=0;i<n;i++)
    {
        srand(i);
        a[i]=rand() % 500; //规定数组的数值小于500
    }
}
void sort(int a[],int n)
{ //选择法数组排序
    int i, j, k=0, t;
    for (i=0; i<n; i++)
     {
        for (j=i; j<n; j++)
        {
            if (a[j]>a[k])
            {
                t=a[j];
                a[j]=a[k];
                a[k]=t; 
            }
        }
        k++;
    }
}
void print(int a[],int n)
{ //输出原数组
    int i;
    for(i=0;i<n;i++)
    {
        if(i%10==0)
            printf("\n");
        printf("%5d",a[i]);
    }
}
int   main(void)
{
    int n,a[200];
    scanf("%d",&n);
    generate(a,n);
    printf("排序前：\n");
    print(a,n);
    sort(a,n);
    printf("\n排序后：\n");
    print(a,n);
    return 0;
}

//冒泡法排序
#include<stdio.h>
int main(void)
{
    int n[10]; int i, j, k, flag;
    for (i=0; i<=9; i++)
        scanf("%d", &n[i]);
    for (i=0; i<=9; i++)
    {
        flag=1;
        for (j=9; j>i; j--)
        {
            if (n[j-1]<n[j])
            {
                k = n[j];
                n[j] = n[j-1];
                n[j-1] = k;
                flag = 0;
            }
        }
        if (flag) break;
    }
    for (i=0; i<=9; i++)
        printf("%5d", n[i]);
    return 0;
}
//输出1~n之间所有素数，每行五个对齐（用转义字符\t）
#include<stdio.h>
int main(void)
{
    int n, number, i, line=0;
    scanf("%d", &n);
    for (number=1; number<=n; number++)
    {
        for(i=2; i<number; i++)
        {
            if (number%i==0)
                break;
        }
        if (i>=number)
        {
            printf("%d\t", number);
            line++;
        }
        if (line==5)
        {
            printf("\n");
            line=0;
        }
    }
    return 0;
}

//写法2
#include<stdio.h>
int main(void)
{
    int n, i, j, flag=1, count=0;
    scanf("%d", &n);
    for (i=2; i<=n; i++)
    {
        flag = 1;
        for (j=2; j<i; j++)
        {
            if (i%j==0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            count++
            printf("%d", i);
            if (count%5==0)
                printf("\n");
        }
    }
    return 0
}

//算法2
#include<stdio.h>
int main()
{
    int a[10000]={1,2,3,5};
    int n, x=3, flag=0, i, j;//x计数器
    scanf("%d",&n);
    printf("%-2d\t%-2d\t%-2d\t",a[1],a[2],a[3]);
    for(i=a[x]; i<n; )
    {
        if (i%6==5)
            i += 2;
        else if (i%6==1)
            i += 4;//增值表达式 
        for (j=1; flag==0 && j*j<=i; j++)
        {
            if (i%a[j]==0) 
                flag = 1;
        }
        if (flag==0 && i<=n)
        {
            x++; a[x]=i;
            if(x%5==0)
                printf("%-2d\n",a[x]);
            else
                printf("%-2d\t",a[x]);
        }
        flag=0;
    }
    return 0;
}
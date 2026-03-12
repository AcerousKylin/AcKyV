//输入10个成绩计算平均分，并输出所有低于平均分的成绩
#include<stdio.h>
int main(void)
{
    double m[10]; int i; double sum=0;
    for (i=0; i<=9; i++)
    {
        scanf("%lf", &m[i]);
        sum += m[i];
    }
    printf("average=%.2f\n", sum/10);
    for (i=0; i<=9; i++)
    {
        if (m[i]<sum/10)
            printf("%-6.1f", m[i]);
    }
    return 0;
}

//输入小于100个成绩，数组嵌套版
#include<stdio.h>
int main(void)
{
    int i=0, j, o=0; int n[100];
    double sum=0, avrg; double m[100];
    while(~scanf("%lf", &m[i]))
    {
        if (m[i]<0)
            break;
        sum += m[i];
        i++;
    }
    avrg = sum / i;
    for (j=0; j<i; j++)
    {
        if (m[j]<avrg)
        {
            n[o]=j;
            o++;
        }
    }
    printf("average=%.2f\n", avrg);
    for (i=0; i<o; i++)
        printf("%-6.1f", m[n[i]]);
    return 0;
}

//输入小于100个成绩，输出最低分和最高分及其脚标
int main(void)
{
    int nax, nin, n=0, i;
    double mark[100]; double min, max;
    while (~scanf("%lf", &mark[n]))
    {
        if (mark[n]<0)
            break;
        n++;
    }
    max = min = mark[0];
    for (i=0; i<n; i++)
    {
        if (mark[i]>max)
        {
            max = mark[i];
            nax = i;
        }
        if (mark[i]<min)
        {
            min = mark[i];
            nin = i;
        }
    }
    printf("最高分为：%.2f,是数组第%d个元素\n", max, nax);
    printf("最低分为：%.2f,是数组第%d个元素"  , min, nin);
    return 0;
}
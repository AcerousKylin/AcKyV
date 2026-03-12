/*8号选手参加校园歌手大赛，编程读入20个整数(0-100之间)并存入数组中做为评委打分。
最后得分计算规则：先计算20个数的平均分，然后去掉所有与平均分相差10分以上的分数
最后把剩下的分数再取平均做为最后得分。如果没有剩下分数，此次打分无效。
输出样式1：
所有评委平均分:87.700分.
不合格得分:70 99 99 .
最后得分:87.412分.
输出样式2：
所有评委平均分:85.050分.
不合格得分:72 72 73 71 71 72 73 71 71 72 98 98 97 100 99 97 97 99 99 99 .
无合格打分.
*/
#include<stdio.h>
#include<math.h>
double avrg(int n,int score[])
{
    int i; double sum=0;
    for (i=0; i<n; i++)
        sum += score[i];
    return sum/n;
}
int main(void)
{
    int mark[25]; int score[25];
    int i=0, j, k=0;
    while (~scanf("%d", &score[i]))
    {
        i++;
    }
    printf("所有评委平均分:%.3f分.\n", avrg(i-1, score));
    for (j=0; j<i; j++)
    {
        if (fabs(score[j]-arvg(i-1, score))>10)
        {
            mark[k] = j;
            k++;
        }
    }
    printf("不合格得分:");
    for (j=0; j<k; j++)
    {
        printf("%d ", score[mark[j]]);
        score[mark[j]] = 0;
    }
    printf(".\n");
    if (avrg(19-k, score)==0)
        printf("无合格打分.");
    else
        printf("最后得分:%.3f分.", avrg(19-k, score));
    return 0;
}
#include<stdio.h>
int main(void)
{
    int n, i;
    scanf("%d", &n);
    int marks[5]={0};
    for (i=0; i<n; i++)
    {
        int score, mark;
        scanf("%d", &score);
        if (score>=90 && score<=100)
            mark = 5;
        if (score>=80 && score<90)
            mark = 4;
        if (score>=70 && score<80)
            mark = 3;
        if (score>=60 && score<70)
            mark = 2;
        if (score<60 && score>=0)
            mark = 1;
        if (score>100 || score<0)
            mark = -1;
        marks[mark-1]++;
    }
    for (i=4; i>=0; i--)
    {
        printf("%d", marks[i]);
        if (i!=0)
            printf(" ");
    }
    return 0;
}
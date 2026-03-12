#include<stdio.h>
int main(void)
{
    int mark, score;
    char assess;
    scanf("%d", &mark);
    if (mark<=100&&mark>=90)
        assess = 'A';
    else if (mark<90&&mark>=80)
        assess = 'B';
    else if (mark<80&&mark>=70)
        assess = 'C';
    else if (mark<70&&mark>=60)
        assess = 'D';
    else if (mark>=0&&mark<60)
        assess = 'E';
    else
    {
        printf("Score is error!");
        return 0;
    }
    printf("%c", assess);
    return 0;
}
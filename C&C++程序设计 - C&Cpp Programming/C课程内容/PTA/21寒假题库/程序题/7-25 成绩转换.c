#include<stdio.h>
int main(void)
{
    int score;
    char mark;
    scanf("%d", &score);
    if (score>=90 && score<=100)
        mark = 'A';
    if (score>=80 && score<90)
        mark = 'B';
    if (score>=70 && score<80)
        mark = 'C';
    if (score>=60 && score<70)
        mark = 'D';
    if (score<60 && score>=0)
        mark = 'E';
    if (score>100 || score<0)
        mark = '#';
    printf("%c", mark);
    return 0;
}
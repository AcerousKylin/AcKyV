#include<stdio.h>
int main(void)
{
    float mark, point;
    scanf("%f", &mark);
    if (mark>100||mark<0)
    {
        printf("Invalid");
        return 0;
    }
    else
    {
        if (mark>=90&&mark<=100)
            point = (mark - 90) / 10 + 4;
        else if (mark>=80&&mark<=89)
            point = (mark - 80) / 10 + 3;
        else if (mark>=70&&mark<=79)
            point = (mark - 70) / 10 + 2;
        else if (mark>=60&&mark<=69)
            point = (mark - 60) / 10 + 1;
        else
        {
            printf("Failed");
            return 0;
        }
    }
    printf("%.1f", point);
    return 0;
}
/*优化写法
#include <stdio.h>
int main(void)
{
    int score;
    scanf("%d", &score);
    if (score < 0 || score > 100)
	    printf("Invalid\n");
    else if (score >= 0 && score < 60)
        printf("Failed\n");
    else
	    printf("%.1f", (1.0 + (score - 60) * 0.1));
    return 0;
}
*/
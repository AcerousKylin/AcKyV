#include<stdio.h>
int main(void)
{
    int t, mark, score; char assess;
    scanf("%d", &mark);
    t = mark/10;
    switch (t)
    {
        case 9 :
            assess = 'A';
            break;
        case 8 :
            assess = 'B';
            break;
        case 7 :
            assess = 'C';
            break;
        case 6 :
            assess = 'D';
            break;
        default :
            if (t>=0&&t<=5)
                assess = 'E';
            else if (mark==100)
                assess = 'A';
            else
            {
                printf("Score is error!");
                return 0;
            }
    }
    printf("%c", assess);
    return 0;
}

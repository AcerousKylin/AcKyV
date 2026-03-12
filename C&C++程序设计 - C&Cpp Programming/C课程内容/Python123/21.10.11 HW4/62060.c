#include<stdio.h>
int main(void)
{
    int set, guess;
    set = 65;
    scanf("%d", &guess);
    if (guess==set)
        printf("Right");
    if (guess>set)
        printf("Big");
    if (guess<set)
        printf("Small");
    else;
    return 0;
}
#include<stdio.h>
int main(void)
{
    float F; //int F
    scanf("%f", &F); //%d ……
    printf("c=%.2f", 5*(F-32)/9);
    return 0;
}
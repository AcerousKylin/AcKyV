#include<stdio.h>
int main(void)
{
    int n, i, mark, xlt, qlf, non;
    xlt = qlf = non = 0;
    scanf("%d\n", &n);
    for (i=0; i<n; i++)
    {
        scanf("%d", &mark);
        if (mark>=85&&mark<=100) xlt++;
        else if (mark>=60&&mark<85) qlf++;
        else if (mark>=0&&mark<60) non++;
        else printf("Error");
    }
    printf("%d %d %d", xlt, qlf, non);
    return 0;
}

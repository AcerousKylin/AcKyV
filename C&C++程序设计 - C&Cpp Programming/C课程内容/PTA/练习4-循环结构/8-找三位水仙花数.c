//找出三位水仙花数
#include<stdio.h>
#include<math.h>
int main(void)
{
    int m, n, i, h, t, s;
    scanf("%d %d", &m, &n);
    if (m>=100&&m<=n&&n<=999)
    {
        for (i=m; i<=n; i++)
        {
            h = i/100;
            t = (i-100*h)/10;
            s = i%10;
            printf("%d %d %d\n", h, t, s);
            if (i==pow(h,3)+pow(t,3)+pow(s,3))
                printf("%d\n", i);
            else;
        }
    }
    else
        printf("Invalid Value.");
}
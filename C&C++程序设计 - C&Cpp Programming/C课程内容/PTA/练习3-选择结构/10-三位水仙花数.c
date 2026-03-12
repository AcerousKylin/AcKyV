#include<stdio.h>
#include<math.h>
int main(void)
{
    int h, t, s, n, pth, ptt, pts, ptsum;
    scanf("%d",&n);
    h = n/100;
    t = (n-100*h)/10;
    s = n-100*h-10*t;
    pth = pow(h,3);
    ptt = pow(t,3);
    pts = pow(s,3);
    ptsum = pth+ptt+pts;
    if (n>=100&&n<=999)
    {
        if (n==ptsum) printf("Yes");
        else         printf("No");
    }
    else printf("Invalid Value.");
    return 0;
}

/*皮球从某给定高度自由落下，触地后反弹到原高度的一半，再落下，再反弹
如此反复。问皮球在第n次落地时，在空中一共经过的距离和第n次反弹的高度*/
#include<stdio.h>
#include<math.h>
int main(void)
{
    int height, n, i;
    double total;
    scanf("%d %d", &height, &n);
    total = 0;
    if (n==0)
        height = 0;
    for (i=0; i<n; i++)
    {
        if (n>0)
        {
            if (i<n-1)
                total += pow(0.5,i)*height+pow(0.5,i+1)*height;
            else
                total += pow(0.5,i)*height;
        }
    }
    printf("%.1lf %.1lf", total, pow(0.5,n)*height);
    return 0;
}
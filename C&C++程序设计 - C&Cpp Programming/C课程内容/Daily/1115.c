#include<stdio.h>
#include<math.h>
int main(void)
{
    int n, i;
    double sum=0;
    scanf("%d",&n);
    for(i=1; ; i++)
    {
        sum += pow(2, i);
        if (sum+pow(2, i+1)>n)
            break;
    }
    printf("%.2lf\n", 0.4*sum/i);
    return 0;
}
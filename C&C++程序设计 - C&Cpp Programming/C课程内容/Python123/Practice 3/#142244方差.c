#include<stdio.h>
#include<math.h>
int main(void)
{
    double n1, n2, n3, n4, fs, s2;
    scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);
    fs = (n1 + n2 + n3 + n4)/4;
    s2 = (pow(n1-fs,2)+pow(n2-fs,2)+pow(n3-fs,2)+pow(n4-fs,2))/4;
    printf("%.4lf", s2);
    return 0;
}
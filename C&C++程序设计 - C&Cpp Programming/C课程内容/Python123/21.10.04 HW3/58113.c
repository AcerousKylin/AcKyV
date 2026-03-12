#include<stdio.h>
#include<math.h>
int main(void)
{
    float a, b, c, s, area, z;
    scanf("%f,%f,%f", &a, &b, &c);
    s = (a+b+c)/2;
    z = s*(s-a)*(s-b)*(s-c);
    area = sqrt(z);
    if (a+b>c&&a+c>b&&b+c>a)
        printf("area=%.2f", area);
    else printf("Error!");
    return 0;
}

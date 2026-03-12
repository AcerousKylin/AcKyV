#include<stdio.h>
#include<math.h>
int main(void)
{
    float a, b, c, s, area, prmt;
    scanf("%f %f %f", &a, &b, &c);
    s = (a+b+c)/2;
    area = sqrt(s*(s-a)*(s-b)*(s-c));
    prmt = a+b+c;
    if (a+b>c&&a+c>b&&b+c>a)
    {
        printf("area = %.2f; perimeter = %.2f", area, prmt);
    }
    else printf("These sides do not correspond to a valid triangle");
    return 0;
}

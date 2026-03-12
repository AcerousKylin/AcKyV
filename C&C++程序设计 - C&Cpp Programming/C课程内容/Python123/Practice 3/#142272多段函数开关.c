#include<stdio.h>
#include<math.h>
int main(void)
{
    double x, y;
    int range;
    scanf("%lf", &x);
    range = x/1;
    switch (range)
    {
        case 1 :
            y = 3*x+5;
            break;
        case 2 :
            y = 2*sin(x)-1;
            break;
        case 3 :
            y = sqrt(1+pow(x,2));
            break;
        case 4 :
            y = pow(x,2)-2*x+5;
            break;
        default :
            printf("No define!");
            return 0;
    }
    printf("%lf", y);
    return 0;
}
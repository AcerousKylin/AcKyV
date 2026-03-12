#include<stdio.h>
int main(void)
{
    float x, c, f;
    char ch;
    scanf("%f%c", &x, &ch);
    c = 5*(x-32)/9;
    f = x*1.8+32;
    if (ch == 'F')
        printf("%.2fC", c);
    else if (ch == 'C')
        printf("%.2fF", f);
    else printf("Error!");
    return 0;
    /*
    switch (ch)
    {
        case ('F') :
            c = 5*(x-32)/9;
            printf("%.2fC", c);
            break;
        case ('C') :
            f = x*1.8+32;
            printf("%.2fF", f);
            break;
        default :
            printf("Error!");
            break;
    }
    return 0;
    */
}

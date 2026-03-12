#include<stdio.h>
int main(void)
{
    float a, b;
    char op;
    scanf("%f%c%f", &a, &op, &b);
    switch (op)
    {
        case '+' :
            printf("%.2f", a+b);
            break;
        case '-' :
            printf("%.2f", a-b);
            break;
        case '*' :
            printf("%.2f", a*b);
            break;
        case '/' :
            if (b==0)
                printf("DataError!");
            else
                printf("%.2f", a/b);
            break;
        default :
            printf("DataError!");
    }
    return 0;
}
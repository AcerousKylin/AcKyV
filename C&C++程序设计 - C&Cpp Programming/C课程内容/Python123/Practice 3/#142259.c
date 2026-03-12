#include<stdio.h>
int main(void)
{
    int a, op, b, c, output;
    scanf("%d %d %d %d", &a, &op, &b, &c);
    switch (op)
    {
        case 1 :
            output = a + b;
            break;
        case 2 :
            output = a - b;
            break;
        case 3 :
            output = a * b;
            break;
        case 4 :
            output = a / b;
            break;
        default :
            if (b==0)
                printf("Invalid Value");
    }
    if (output==c)
        printf("GOOD");
    if (output!=c)
        printf("SORRY");
    return 0;
}
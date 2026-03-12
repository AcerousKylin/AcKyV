#include<stdio.h>

void main(void) {
    double a=20, b=5;
    int c;
    for (c=1; c<=10; c++) {
        double d;
        if (a == b)
            break;
        else if (a < b) 
            d = b / a;
        else {
            d = a / b;
        }
    }
    printf("a = %lf, b = %lf", &a, &b);
    return;
}
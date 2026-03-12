#include<stdio.h>

void mprint() {
    printf("12345");
}

void main(void) {
    int i = 0;
    do
    {
        mprint();
    } while(i++ <= 3);
    return;
}
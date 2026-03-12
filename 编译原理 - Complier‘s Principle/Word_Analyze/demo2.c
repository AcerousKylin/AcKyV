#include<stdio.h>

void main(void) {
    float _a1=20, _b2=10.0;
    short c3=11;
    while (c3-- <= 0) {
        long d;
        if (_a1 == _b2)
            break;
        else if (_a1 < _b2) 
            d = _b2 / _a1;
        else {
            d = _a1 / _b2;
        }
    }
    printf("a = %lf, b = %lf", &_a1, &_b2);
    return;
}
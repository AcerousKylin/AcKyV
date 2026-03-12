#include <stdio.h>

typedef struct
{
    double rp, ip;
} COMPLEX;

int main()
{
    COMPLEX a, b, c;

    scanf("%lg%lgi", &a.rp, &a.ip);
    scanf("%lg%lgi", &b.rp, &b.ip);

    /* 你提交的代码将被嵌在这里 */

    c.rp = a.rp + b.rp;
    c.ip = a.ip + b.ip;

    printf("%g%+gi\n", c.rp, c.ip);

    return 0;
}
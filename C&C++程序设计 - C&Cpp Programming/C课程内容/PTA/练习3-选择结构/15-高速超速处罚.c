#include<stdio.h>
int main(void)
{
    float sped, lim, x, lim1, lim2;
    scanf("%d %d", &sped, &lim);
    x = (sped/lim-1)*100;
    lim1 = lim*1.1;
    lim2 = lim*1.5;
    if (sped>0&&sped<lim1) printf("OK");
    else if (sped>=lim2)
        printf("Exceed %.0f%%. License Revoked", x);
    else if (sped>=lim1&&sped<lim2)
        printf("Exceed %.0f%%. Ticket 200", x);
    else;
    return 0;
}

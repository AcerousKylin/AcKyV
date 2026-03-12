#include<stdio.h>
int main(void)
{
    int gram, e, stage, flood, extfe, d;
    scanf("%d %c", &gram, &e);
    stage = gram/500; flood = gram%500; extfe = (gram-1000)/500;
    if (stage<2)
        d += 8;
    else if (stage>=2)
    {
        if (flood==0)
            d += 8+extfe*4;
        else 
            d += 8+(extfe+1)*4;
    }
    if (e=='y')
        d += 5
    printf("%d", d);
    return 0;
}
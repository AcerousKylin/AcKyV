/*一对兔子，从出生后第3个月起每个月都生一对兔子
小兔子长到第3个月后每个月又生一对兔子
假如兔子都不死，这第1个月出生的一对兔子
至少需要繁衍到第几个月时兔子总数才可以达到N对*/
#include <stdio.h>
int main(){
    double n, o=0, p=1, midst, month=1;
    scanf("%lf", &n);
    while (p<n)
    {
        month++;
        midst = o;
        o = p;
        p += midst;
    }
    printf("%f", month);
    return 0;
}
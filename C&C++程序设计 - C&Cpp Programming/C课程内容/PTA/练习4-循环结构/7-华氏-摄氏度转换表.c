//输出华氏-摄氏温度转换表
#include<stdio.h>
int main(void)
{
    int i, upr, lwr;
    float o, f;
    scanf("%d %d", &lwr, &upr);
    if (lwr>0&&lwr<=upr&&upr<=100)
    {
        printf("fahr celsius\n");
        for (i=lwr; i<=upr; i+=2)
        {
            o = i;
            f = 5*(o-32)/9;
            /*
            if (i>0&&i<10)
                printf("%d   %.1f\n", i, f);
            else if (i>=10&&i<32)
                printf("%d  %.1f\n", i, f);
            else if (i>=32&&i<=99)
                printf("%d   %.1f\n", i, f);
            else if (i=100)
                printf("%d  %.1f\n", i, f);
                */
            printf("%d%6.1f\n",i ,f);
        }
    }
    else printf("Invalid.");
    return 0;
}

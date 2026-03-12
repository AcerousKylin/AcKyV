/*
#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void)
{
    char a[20], *p=a; int i;
    gets(a);
    for (i=0, p=a; i<strlen(a); i++, p++)
    {
        if ((*p>='A' && *p<='V') || (*p>='a' && *p<='v'))
            *p += 4;
        if ((*p>'V' && *p<='Z') || (*p>'v' && *p<='z'))
            *p -= 22;
   }
   puts(a);
   return 0;
}
*/

/*
int main(void)
{
   int maxn;
   scanf("%d",&maxn);
   int apd=2, total=2, day=1;
   while (total<=maxn)
   {
        apd = apd * 2;
        day++;
        total += apd;
   }
   double avrg = 1.20 * total / day;
   printf("Average=%.2f", avrg);
    return 0;
}
*/
#include<stdio.h>
int main(void)
{
    int i, n, mark, a, b, c, d, e;
    scanf("%d\n", &n);
    a = b = c = d = e = 0;
    for (i=0; i<n; i++)
    {
        scanf("%d", &mark);
        if (mark>=90&&mark<=100) a++;
        else if (mark>=80&&mark<90) b++;
        else if (mark>=70&&mark<80) c++;
        else if (mark>=60&&mark<70) d++;
        else if (mark<60&&mark>=0) e++;
        else
        {
            printf("Error");
            return 0;
        }
    }
    printf("%d %d %d %d %d", a, b, c, d, e);
    return 0;
}

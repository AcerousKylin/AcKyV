#include<stdio.h>
#include<math.h>
int main(void)
{
    int n, i, a, mid=0, s=0;
    scanf("%d, %d", &a, &n);
    for (i=0; i<n; i++)
    {
        /*mid += pow(10, i)*a;
        s += mid;*/
        mid += mid*10+a; //更简短的写法
        s += mid;
    }
    printf("%d", s);
    return 0;
}
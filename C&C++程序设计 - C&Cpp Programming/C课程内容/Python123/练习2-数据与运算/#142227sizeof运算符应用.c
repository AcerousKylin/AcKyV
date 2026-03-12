#include<stdio.h>
int main(void)
{
    printf("%d %d %d %d %d %d %d",
        sizeof(double), sizeof(long double), sizeof(long long),
        sizeof(3.14F), sizeof(3.14), sizeof(521), sizeof(521LL));
        return 0;
}
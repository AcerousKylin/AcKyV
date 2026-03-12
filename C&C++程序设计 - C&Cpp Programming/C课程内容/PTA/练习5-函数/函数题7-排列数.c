/*根据公式P(m n)=(n−m)!/n!
算出从n个不同元素中取出m个元素（0<m≤n）的排列数
*/

#include <stdio.h>

double fact( int n );

int main(void)
{    
    int m, n;
    double result; 

    scanf("%d%d", &m, &n);
    if(m > 0 && n > 0 && m <= n){
        result = fact(n)/fact(n-m);
        printf("result = %.0f\n", result);    
    }

    return 0;
}

/* 请在这里填写答案 */

double fact( int n )
{
    if (n==1||n==0)
        return 1;
    return n * fact(n-1);
}
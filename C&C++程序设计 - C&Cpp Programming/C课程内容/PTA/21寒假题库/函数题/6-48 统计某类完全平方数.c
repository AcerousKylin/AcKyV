#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;
    
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

/* 你的代码将被嵌在这里 */

int IsTheNumber ( const int N )
{
    int number[10];
    int n=N, i, j=0, k, flag=0;
    for (i=0; i<=N; i++)
    {
        if (i*i==N)
            flag = 1;
    }
    if (!flag)
        return 0;

    flag = 0;
    for(i=0; n!=0; i++)
    {
        number[i] = n % 10;
        n /= 10;
    }
    for(j=0; j<i; j++)
    {
        for (k=j+1; k<i; k++)
            if (number[j]==number[k])
            {
                flag = 1;
                break;
            }
    }
    return flag;
}
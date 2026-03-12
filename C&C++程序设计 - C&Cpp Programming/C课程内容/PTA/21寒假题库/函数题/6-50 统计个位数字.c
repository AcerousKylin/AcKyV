#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
    
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

/* 你的代码将被嵌在这里 */

#include<math.h>

int Count_Digit ( const int N, const int D )
{
    int number[10];
    int n=abs(N), i, j, count=0;
    if (N==0 && D==0)
        return 1;
    for(i=0; n!=0; i++)
    {
        number[i] = n % 10;
        n /= 10;
    }
    for(j=0; j<i; j++)
        if (D==number[j])
            count++;
    return count;
}
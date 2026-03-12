//哥德巴赫猜想
//任何一个充分大的偶数(>=6)都可以表示成两个奇素数的和的形式
//输入一个大于6的正偶数，输出将其表示后为两个奇素数的所有算式
#include<stdio.h>
int IsPrime( int n )
{
    int i;
    for (i=2; i<n; i++)
    {
        if (n%i==0)
            return 0;
    }
    return 1;
}
int main(void)
{
    int even, odd1, odd2;
    scanf("%d", &even);
    for (odd1=2; odd1<even/2; odd1++)
    {
        if (IsPrime(odd1)==0 || odd1%2==0)
            continue;
        for (odd2=2; odd2<even; odd2++)
        {
            if (IsPrime(odd2)==0 || odd2%2==0)
                continue;
            if (odd2+odd1==even)
                printf("%d=%d+%d\n", even, odd1, odd2);
        }
    }
    return 0;
}

////输入区间，输出多组数据
#include<stdio.h>
int IsPrime( int n )
{
    int i;
    for (i=2; i<n; i++)
    {
        if (n%i==0)
            return 0;
    }
    return 1;
}
int main(void)
{
    int a, b, even, odd1, odd2;
    scanf("%d %d", &a, &b);
    for (even=a; even<=b; even++)
    {
        for (odd1=2; odd1<even/2; odd1++)
        {
            if (IsPrime(odd1)==0 || odd1%2==0)
                continue;
            for (odd2=2; odd2<even; odd2++)
            {
                if (IsPrime(odd2)==0 || odd2%2==0)
                    continue;
                if (odd2+odd1==even)
                {
                    printf("%d=%d+%d\n", even, odd1, odd2);
                    goto HERE;
                }
            }
        }
        HERE:;
    }
    return 0;
}
/*
    题号：3729
    注意数据范围。最优解在O（nlogn）
    i次操作后数组长度就自然为i，操作的区间在i-ai~i，将他们变为1。
    暴力枚举最坏为O（n），操作需要O（n），O（n^2）
    优化：
        是经典的差分操作：也就是多次选取数组的某一段，加上一个数
        然后用线性的复杂度将数组输出出来。
        代替变换0、1，开另外的数组来记录每个位置被操作的次数
        或者用区间合并（基础课第一讲最后一个点）
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010; // n will not beyond 2*10^6

int n; // n is the number of the operation that will be applied to b
int b[N];

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        memset(b, 0, (n+1)*4);
        /*  it's for a clean array full of 0 in multiple examples
            if we use memset(b, 0, sizeof(b)); to clear array, there'll be a risk of overtime
            because N*n*4 = 1.6billion, so'd better put a proper length on
            and then n+1 will not beyond 2*10^5, it's worthy
        */  

        for (int i=1; i<=n; i++) 
        // i is which operation is dealing and also the length of array
        // 'cause we put an extra 0 at the tail in each step
        {
            int x; // temporary variety for input ai
            scanf("%d", &x);
            x = min(x, i); // if ai bigger than i, just modify x to i
            int l=i-x+1, r=i;
            // l is where operation starts in array, r is the opposite function
            b[l]++;
            b[r+1]--;
            // this is finite difference's format, please check it out
        }
        for (int i=1; i<=n; i++)// finite difference to recover every number we need
            b[i] += b[i-1];

        for (int i=1; i<=n; i++)
            printf("%d ", !!b[i]);
            // any number equals or bigger than 1 was applied NOT will become 0
            // and 0 was applied NOT will become 1, that's what we want
        puts("");
    }
    return 0;
}
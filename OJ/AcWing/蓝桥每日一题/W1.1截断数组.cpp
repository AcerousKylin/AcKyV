/*
    题号：3956
    本题需要在数组中选两个点，如果暴力枚举，时间复杂度为o(n^2)
    而对10^5的数据来说，应该将其限制在nlogn（详见yxc的数据范围贴）
    因此最多枚举一次（n），然后再做处理。
    由于截断三段元素的根据就是每段的和，因此我们才使用前缀和
    先枚举一个点，然后在第一个点枚举的每种情况下去定第二个点
    然后把每种枚举中所有的可能相加即可。
*/


#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

//the extreme number of divisions shall be C|2|n=5*10^9
//and int's limit goes to 2.1*10^9, so you'll need long long
typedef long long LL;

const int N = 100010;

int n;
int s[N];
// but the array shall not be overflowed, element is 10^5


int main(void)
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    { // input and pre-process, be careful that it start with 1
        int x;
        scanf("%d", &x);
        s[i] = s[i-1] + x;
        // elements of the array record the sum of itself and all number in front of it
    }
    
    if (s[n] % 3) //summary must be a multiple of 3
        puts("0");
    else
    {
        LL result=0, count=0; // long long for sure
        for (int j=2; j<n; j++) // j is the last of the second division
        { // the second divide happens after 1, like 0|1|2...
            if (s[j-1] == s[n]/3) // searching for the first point
                count++; // it's a certain number, doesn't change by the second division
            
            // actually the two steps do counting seperatedly
            
            if (s[j] == 2*s[n]/3)
                result += count; // every the second division adds all variation of the first division for one time
        }

        printf("%lld", result); // and it's the result
    }
    return 0;
}
/*
    题号：1230
    本题的数据范围在1e5，暴力枚举的时间复杂度是O(n^2)，必须要缩减到O(nlogn)及以下
    利用前缀和，可以优化一部分，在此基础上，可以通过题目性质入手优化
        先枚举一个右端点，再枚举左端点，计算ai-aj取模是否等于零
        也就相当于，aj与ai模k的结果是否相同，只要是相同的模取结果的点之间就会有一个区间符合要求
        若仅为了计算数量，无需存储所有aj的模，只要计得与ai取模结果相同的aj数量即可
        只要在遍历过程中，根据已有的前缀和取模值相同的点的数量计算结果，再根据当前点的取模值更新记录（先后顺序）
        最后就能得到结果。
    这样，时间复杂度降为O(n)，是可以通过的。
    此外，对于前缀和，10^5*10^5=10^10，超过了int的数据范围，要用long long；
    对于结果，大概为10^10/2=5*10^9，仍然超出了int的数据范围，也要用long long。
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N=100010;

int n, k;
LL pre[N], cnt[N]; //cnt shall not be oversize, but it's fine

int main(void)
{
    scanf("%d %d", &n, &k);

    for (int i=1; i<=n; i++)
    { // prefix summary
        scanf("%lld", &pre[i]);
        pre[i] += pre[i-1];
    }

    LL result=0;
    cnt[0] = 1;
    /* Why cnt[0] should start with 1?
    While enumerating the right boundry of section, certainly it should have a left one
    In the orginal array, if the first section we meet range from 1 to i, you'll find that
    there's no left point(last availiable point) exist for us to count this section in,
    as a result of that, we're likely to put a virtual left point for counting section properly at zero.
    Which means the 0 position will not be counted, but just as a temporary point. 
    */ 
    for (int i=1; i<=n; i++)
    {
        result += cnt[pre[i]%k];
        // with each point that in front of the current point, the new point could build a section
        cnt[pre[i]%k]++;
        // then update the current point's value into the cnt
    }

    printf("%lld\n", result); // output with long long

    return 0;
}
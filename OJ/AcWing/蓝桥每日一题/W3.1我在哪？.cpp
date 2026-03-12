/*
    题号：1460
    字符串最大长度仅有100，如果暴力求解
        枚举K（循环n次），再枚举任意子串两次（两重循环n-K+1次，可以减去一半重复的）
        然后检查是否相同（又一重循环K次），大约为O(n^4)，也就是10^8(但在这些限制下其实远小于这个值)
    优化可以使用二分：
        能不能二分在于数据有没有二段性。
        答案的范围在1~n之间，假设答案为ans，那么所有小于ans的答案都不合法，而大于等于ans的答案都合法吗？
        利用反证法：
            假设这个时候存在两个更长的相同子串，自然我们知道有更小的子串存在，所以这个时候这两个更长串的子串一定有相同的子串
            所以所有小于ans的答案都不合法，而大于等于ans的答案都合法
        第一重循环不再枚举，二分K，时间复杂度O(n^3logn)，n最多为100，logn为7~8，快了很多
        第二三重循环需要寻找相同的子串，可以改用哈希表O(n^2logn)
        甚至可以使用字符串哈希，将复杂度降至O(nlogn)（以下代码没有实现）
            1.如果mid成立，那么mid右侧一定存在相同子串，左侧不一定
            mid也可能是答案，所以边界一定在mid或mid左侧；
            2.如果mid不成立，那么mid左侧一定不存在相同子串，右侧不一定
            mid不可能是答案，所以边界一定在mid左侧。
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int n;
string str;

bool check(int mid)
{
    unordered_set<string> hash;s

    for (int i=0; i+mid-1<n; i++)
    {
        string s=str.substr(i, mid);
        if (hash.count(s))
            return false;
        hash.insert(s);
    }

    return true;
}

int main(void)
{
    cin >> n >> str;

    int l=1, r=n;
    while (l < r)
    {
        int mid = (l+r)>>1;
        if (check(mid))
            r = mid
        else
            l = mid + 1;
    }

    cout << r << endl;

    return 0;
}

/* 暴力求解

int n;
string str;

int main(void)
{
    cin >> n >> str;

    for (int k=1; k<=n; k++) // k is needed array's length
    {
        bool flag = false;

        // i is the position as the beginning of string we're enumerating firstly
        // and i+k-1 restricts our boundry for rejecting invalid substring we're enumerating
        for (int i=0; i+k-1<n; i++)
        {
            // j is in order to enumerate whether there's a substring is the same as substring i
            // and be careful that j should start after the substring i
            for (int j=i+1; j+k-1<0; j++)
            {
                bool same = true; // to decide whether the two substring is the same
                for (int u=0; u<k; u++)
                    if (str[i+u] != str[j+u]) // check them one by one
                    {
                        same = false;
                        break;
                    }

                // after check finished, if they're the same, it means we find one and no need for more checks
                // if not, it'll go to find a string of more units that fits the condition
                if (same) 
                {
                    flag = true;
                    break;
                }
            }
            if (flag) // mean to cut extra searching, if existing, then go to next unit
                break;
        }
        if (!flag) // if it's not, k haven't been changed, now the k is the answer
        {
            cout >> k >> endl;
            break;
        }
    }

    return 0;
}

*/
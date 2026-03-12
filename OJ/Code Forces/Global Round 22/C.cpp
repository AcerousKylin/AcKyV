#include<bits/stdc++.h>
using namespace std;

void solve(void)
{
    int n;  cin >> n; // 有n个数
    int o=0,e=0; // o=odd奇数, e=even偶数
    for(int i=1; i<=n; i++)
    {
        int t;  cin >> t;
        if(t%2 == 0) // 计算奇数偶数的数量
            e++;
        else
            o++;
    }

    // 为什么是4？

    /*
    因为Alice取偶数对其获胜无关，主要研究奇数
    那么对于奇数，只有Alice取到两次奇数才有获胜的条件
    那么对于Alice的两次取数，也就是两回合共四次取数
    而对于四个数字为一轮中的所有情况进行讨论
    四奇四偶对于获胜无关，三奇一偶A必胜，二奇二偶B必胜
    对于一奇的情况，取决于剩余偶数的个数：偶数个偶数则A必败，反之不然。
    */
    
    // 接下来首先判断奇数的个数，
    if(o%4==0 || o%4==3) // 如果4奇数余1个奇数都没有或者有1个偶数
        puts("Alice"); // Alice必胜(全偶必胜;A奇必2奇,A绝不拿偶)
    else if(o%4==2) // 如果最后4个数字中有2个奇数
        puts("Bob"); // Bob必胜(A偶B偶,A奇B奇,无论如何A都会拿到单独的奇)
    else // 如果余有1个奇数
    {
        if(e%2==0) // 同时偶数剩余偶数个
            puts("Bob"); // 那么Bob必胜(B仅拿偶,A最后必奇)
        else // 反之
            puts("Alice"); // Alice必胜(A仅拿偶,B最后奇)
    }
}

int main(void)
{
    int T;
    cin >> T;
    while(T--)
        solve();
}
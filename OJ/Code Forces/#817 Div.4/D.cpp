#include<bits/stdc++.h>
using namespace std;

/*
    先遍历第一次，将原总值算出来
    遍历第二次，将每个位置变换方向后的变化值存起来
    两次遍历可以同时进行，遍历后为所有变化值进行排序
    最后在原值基础上加正的变化值，直到变化不能带来增值
    每次加都输出一次，最后不能增值便不加，单单输出
*/

typedef long long ll;
const int N = 1e5+10; // 每行的人数不超过2e5

void solve(void)
{
    vector<int> a; // 动态数组a,用于存储每个人转向后为总值带来的变化值
    ll ans = 0; // 每次用以输出的answer变量
    int n;  cin >> n;
    string s;   cin >> s; // s用于读入每个案例初始的人物看向
    for(int i=1; i<=n; i++) // i从0开始亦可,i-1改为i,i改为i+1
    {
        int t; // 暂时存放人转向后为总值带来的变化
        if(s[i-1] == 'L') // 看向左边的人
        {
            ans += (i-1); // 计算换向前的总值
            t = (n-i) - (i-1); // 换向后的变化值
        }
        else
            t = (i-1) - (n-i), ans += (n-i); // 同理
        a.push_back(t); // 最后将t推入a中
    }
    sort(a.begin(), a.end(), greater<int>()); // 将变化值从高到低排序
    for(int i=0; i<n; i++)
    {
        if (a[i] > 0) // 如果变化这个能增加总值
            ans+=a[i]; // 在原总值的基础上加上变化值
        cout << ans << " "; // 直接输出(没有贡献的不加)
    }
    cout << endl; // 多个案例,记得回车
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--)
        solve();
}
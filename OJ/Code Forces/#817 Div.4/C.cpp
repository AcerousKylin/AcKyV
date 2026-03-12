#include<iostream>
#include<map>
using namespace std;

void solve(void)
{
    string s[5][1000]; // 用来存放所有人写的"单词"
    int ans[5]={0}; // 用来存放每个人的分数
    map<string,int> m; // 映射,前者为下标,后者为值
    int n;  cin >> n;
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> s[i][j]; // 读入所有字符串
            m[s[i][j]]++; // 对应字符串的映射值+1,其默认为0
        }
    }

    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(m[s[i][j]]==1) // 如果字符串出现过1次
                ans[i]+=3; // 对应人+3分
            else if(m[s[i][j]]==2) // 如果字符串出现过2次
                ans[i]+=1; // 对应俩人+1分
        } // 其他情况不加分
    }

    for(int i=1; i<=3; i++)
        cout << ans[i] << " "; // 输出每个人的分数
    cout << endl; // 多个案例,记得回车

}
int main(void)
{
    int T;
    cin >> T;
    while(T--)
        solve();
}
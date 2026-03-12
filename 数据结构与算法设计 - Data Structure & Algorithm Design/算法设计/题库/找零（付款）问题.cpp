/*类型：动态规划、简单循环
 *假设有m种面值的货币
 *(为降低难度，m=5。money[5]={30,10,8,5,1})需要找给顾客n角现金
 *付款问题（payment problem）要求找到一个付款方案
 *本题要求：动态规划法求最优值，付出的货币张数最少是多少？
*/

#include <iostream>
using namespace std;
#define Bignum 999999
int money[5]={30,10,8,5,1};//无偏见、无遗漏、无重复
int pay[9999]={0};//pay[i]表示找i元的最少张数是pay[i]。
//不要改变上面的数据，请完成下面payMent的函数体
int payMent(int n)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return Bignum;
    if (pay[n] != -1)
        return pay[n];
    else
        pay[n] = Bignum;
    for (int i=0; i<5; i++)
        pay[n] = min(pay[n], payMent(n-money[i])+1);
    return pay[n];
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<9999;i++)
        pay[i] = -1;//备忘录赋初值
    cout<<payMent(n);
    return 0;
}

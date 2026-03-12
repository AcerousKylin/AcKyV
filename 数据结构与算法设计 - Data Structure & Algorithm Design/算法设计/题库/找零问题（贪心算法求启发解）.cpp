/*类型：简单循环
 *假设有面值为 5元、2元、1元、5 角、2 角、1 角的货币，需要找给顾客n角现金
 *付款问题（payment problem）要求找到一个付款方案
 *本题要求：贪心算法求启发解，付出的货币张数是多少？
 *（编程模板中有三处错误，请您改正。并思考如何用动态规划法求最优解？）
*/

#include <iostream>
using namespace std;
int main()
{
    int money[6] = {50, 20, 10, 5, 2, 1}, i, cnt = 0, n;
    cin>>n;
    for (i = 0; i < 6; i++) /*选取面值依次试探*/
    {
        if (n >= money[i])
        {
            cnt += n / money[i]; // 应该是除而非取余
            n = n % money[i]; // 应该是取余而非除
            if(!n) // 应该当n为0时退出循环
                break;
        }
    }
    cout << cnt;
    return 0;
}

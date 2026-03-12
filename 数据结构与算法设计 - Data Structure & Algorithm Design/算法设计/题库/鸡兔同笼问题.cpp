/*类型：约束条件比经典鸡兔同笼问题宽松，无头的个数约束，直接模拟法。
 *【问题】笼子里有若干只鸡和兔子，鸡有两只脚、兔子有四只脚，没有例外情况。
 *已知笼子里脚的个数，问笼子里至多有多少只动物？至少有多少只动物？
 *【想法】对于同样数目的动物，鸡脚的总数肯定比兔子脚的总数要少，
 *因此在计算笼子里至多有多少只动物时，应该把脚都算作鸡脚；
 *在计算笼子里至少有多少只动物时，应该尽可能把脚都算作兔子脚。
*/

#include <iostream>
using namespace std;
int main()
{
    int feets, maxNum, minNum,rabbits;
    cin>>feets;//把其余代码写在下面:
    if (feets < 2 || feets % 2 == 1)
    {
        cout << "不合常理" << endl;
        return 0;
    }
    else
    {
        maxNum = feets / 2;
        rabbits = feets / 4;
        minNum = rabbits + (feets - 4 * rabbits) / 2;
        cout << "至多有"<<maxNum<<"只动物；至少有"<<minNum<<"只动物，其中兔子"<<rabbits<<"只。";
        return 0;
    }
}

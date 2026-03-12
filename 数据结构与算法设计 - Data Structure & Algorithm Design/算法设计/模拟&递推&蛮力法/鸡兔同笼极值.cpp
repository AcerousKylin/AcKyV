#include <iostream>
using namespace std;
int main()
{
    int feets, maxNum, minNum,rabbits;
    cin>>feets;//把其余代码写在下面:
    if (feets % 2 == 0)
    {
        maxNum = feets / 2;
        if (feets % 4 == 0)
            minNum = feets / 4;
        else
            minNum = (feets-2) / 4 + 1;
    }
    else
    {
        cout << "不合常理" << endl;
        return 0;
    }
    cout << "至多有"<<maxNum<<"只动物，至少有"<<minNum<<"只动物，其中兔子"<<rabbits<<"只。";
    return 0;
}

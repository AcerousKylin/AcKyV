/*输入方阵的大小
 *输出方阵
*/

#include <iostream>
#include <iomanip>
using namespace std;
int num=0,d[100][100]={0},i=0,j=0;
void Full(int size,int starti)//请大家实现该函数，完成题目要求：
{   
    if (size == 0)
        return;
    if (size == 1)
    {
        d[starti][starti] = ++num;
        return;
    }
    for (i=0; i<size-1; i++)
        d[starti+i][starti] = ++num;
    for (j=0; j<size-1; j++)
        d[starti+i][starti+j] = ++num;
    for (i=0; i<size-1; i++)
        d[size-1+starti-i][starti+j] = ++num;
    for (j=0; j<size-1; j++)
        d[size-1+starti-i][size-1+starti-j] = ++num;
    return Full(size-2, starti+1);
}
int main()
{
    int size;
    cin>>size;
    Full(size,0);
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
            cout<<setw(4)<<d[i][j];
        cout<<endl;
    }
}
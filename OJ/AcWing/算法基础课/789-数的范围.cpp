/*
    整数二分的本质：
    有单调性可以二分；可以用二分的不一定有单调性。
    在区间[l, r]上定义了某种性质，使得一边满足，一边不满足（边界不重叠）
    二分就可以寻找这种性质的边界（一边为满足性质的边界或另一边为满足性质的边界）
    模板1：寻找左边为满足性质的边界：
        1.找中间值mid=(l+r+1)/2，检查mid是否符合性质；
        2.若满足，则所寻找的边界在[mid, r]（mid可能是答案），用l=mid来更新；
        若不满足，则所寻找的边界在[l, mid-1]（mid不是答案），用r=mid-1来更新。
    模板2：寻找右边为满足性质的边界：
        1.找中间值mid=(l+r)/2，检查mid是否符合性质；
        2.若满足，则所寻找的边界在[l, mid]（mid可能是答案），用r=mid来更新；
        若不满足，这所寻找的边界在[mid+1, r]（mid不是答案），用l=mid+1来更新。
    若干问题：
        1.如何选择用哪个模板？
        首先根据题意写出检查性质的函数bool check(mid)
        再根据函数输出t/f的更新方法以及答案的需求去选择模板
        2.为什么第一个模板要mid里的l+r要+1？
        由于C/C++中整数除法为向下取整，所以当l=r-1时，若mid=(l+r)/2，那么mid=l
        更新后，l=mid=l，也就是说循环前后判断的区间没有变化，就导致了死循环
        因此，需要给l+r加上1，来防止死循环
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N=100010;

int arr[N]; // array
int n, q; // n is the length of arr, q is the number of examples 

int main(void)
{
    // initial input
    scanf("%d %d", &n ,&q);
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    // for each cases:
    while (q--)
    {
        int k; // k is the number we're looking for
        scanf("%d", &k);

        int l=0, r=n-1;
        // l is the left of our search scope
        // r is the right if our search scope

        while (l < r)
        // make l and r legal in searching cycles
        {
            int mid=(l+r)>>1; // make up a mid for searching
            // this actually finding the very left of the answer
            if(arr[mid] >= k)
                r = mid;
            else
                l = mid + 1; // mid is not right
        }

        // if left of the searching zone even bigger than k, then it's not exist
        if (arr[l] != k)
            cout << "-1 -1" << endl;
        else
        {
            // output the answer we've already found
            // because we need l to search the right side 
            cout << l << ' ';

            l = 0; r = n-1; // reset l and r
            while (l < r) // still make sure they're legal
            {
                int mid = (l+r+1)>>1; // watch out for +1
                // now this time, finding the right side
                if (arr[mid] <= k)
                    l = mid;
                else
                    r = mid - 1; // mid is not right
            }

            // and finally the answer of right side
            // and notice that if left side exists, so do right side
            cout << l << endl;
        }
    }

    return 0;
}
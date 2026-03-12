/*
    题号：95
    首先我们会发现，在整个流程里，按钮顺序是无关紧要的
    枚举第一行的操作，那么会有2^5个种按法（按或不按），且每个格子最多按一次（两次没有意义）
    这个时候，因为第一行的按钮不能再操作了，又要让第一行全亮，，因此必须要根据第一行的状态去按第二行（第一行灭的列，第二行一定要按，反之亦然），以此类推。
    也即每一行（除第一行）开关的操作，完全取决于上一行灯的亮灭状态。
    最后n-1行一定是全亮的，只要特判一下最后一行是否全亮来判断这次枚举第一行的操作正确与否。
    最后的最后还要确定按的次数（更新最少次数）。

    如何枚举第一行操作？
        其实就是指数类型枚举。这里就推荐使用位运算了。
        二进制数和十进制数的转换，0~31就表示了5位的所有方案。
        判断i二进制数的第k位是否是1，也就是i>>k & 1的结果（i右移k位，取出最低位和1进行与运算即可）
    如何进行开关操作？
        用坐标+偏移量来操作
    时间复杂度？
        第一行2^5 * 所有开关25 * 开关一次5 * 数据量500 = 2e6
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 6;

char g[N][N], backup[N][N]; // g is the original matrix, backup is the backup of g for practical operating
int dx[5] = {-1, 0, 1, 0, 0}, dy[5] = {0, 1, 0, -1, 0};


void turn(int x, int y)
{
    for (int i=0; i<5; i++)
    {
        int a = x+dx[i], b = y+dy[i];
        if (a < 0 || a >= 5 || b < 0 || b >= 5) // checking the boundries, if exceeded, ignore it
            continue;
        g[a][b] ^= 1; // '0'=48(110000 B), '1'=49(110001 B), so we xor the value with 1 for swaping 1 and 0; 
    }
}

int main(void)
{
    int T; // group number of testing data
    cin >> T;
    while (T--)
    {
        for (int i=0; i<5; i++)
            cin >> g[i]; // input the data as several strings

        int res = 10; // we set a high score waiting for comparing with the final steps
        for (int op=0; op<32; op++) // op means time of the first line's operations
        {
            memcpy(backup, g, sizeof(g)); // copy g to backup in order to save the orginal state of the matrix
            int step = 0; // it's steps we are operating
            for (int i=0; i<5; i++)
                if(op>>i & 1) // whether this operation set the(each) position into 1, find it(spawn a situation by the number we set)
                {
                    step++; // count it up
                    turn(0, i); // turn the light itself and ones around it
                }
            
            for (int i=0; i<4; i++) // apply the fore four lines' operations by last line
                for (int j=0; j<5; j++)
                    if (g[i][j] == '0')
                    {
                        step++; // count it up
                        turn(i+1, j); // turn the lights below the first line by the state after the first-line operations
                    }
            
            bool dark = false; // to judge whether there's any light was off in the last line
            for (int i=0; i<5; i++)
                if (g[4][i] == '0') // searching for doused lights
                {
                    dark = true;
                    break;
                }

            if (!dark)
                res = min(res, step); // compare and get a minimum value of the step
            memcpy(g, backup, sizeof(g)); // copy backup to g for recovering the origin state for the next enumeration
        }

        if (res > 6)
            res = -1; // the matrix doesn't have a group of proper operations to limit the number of steps below 6
        cout << res << endl;
    }

    return 0;
}
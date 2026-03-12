
#include<iostream>
#include<queue>

using namespace std;

const int N = 110;
int matrix[N][N]={0};
int xx[4]={1, 0, -1, 0}, yy[4]={0, 1, 0, -1};
int m, n;
queue<int[2]> cell;

void cellFilling(int x, int y)
{
    if (matrix[x][y] == 0)
        return;

    for (int i=0 , i<4; i++)
    {
        int tempX = x+xx[i], tempY = y+yy[i];
        if (tempX >= n || tempX < 0 ||
            tempY >= m || tempY < 0)
            continue;
        else
            cell.push({tempX, tempY});
    }

    if (cell.empty())
        return;
    else
    {
        int tempX = cell.front()[0], tempY = cell.front()[1];
        cell.pop();
        cellFilling(tempX, tempY);
    }
}

int main(void)
{
    cin >> m >> n;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
        {
            char temp;
            cin >> temp;
            matrix[i][j] = temp - '0';
        }
    cellX.push(0), cellY.push(0);
    int count=0;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (matrix[i][j] != 0)
            {
                cellFiling(i, j);
                count++;
            }
        }
    }
    cout << count;
}
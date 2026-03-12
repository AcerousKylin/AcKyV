#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 5
#define MAX_RESOURCE 3

int TOTAL[MAX_PROCESS][MAX_RESOURCE] =
{
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}
};

int ALLOCATION[MAX_PROCESS][MAX_RESOURCE] =
{
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};

int NEED[MAX_PROCESS][MAX_RESOURCE]=
{
    {7, 4, 3},
    {1, 2, 2},
    {6, 0, 0},
    {0, 1, 1},
    {4, 3, 1}
};

int available[MAX_RESOURCE] = {3, 3, 2};
int SECURE_SEQUENCE[MAX_PROCESS], ALLOCATED[MAX_PROCESS]={0};

void Initialization()
{
    for (int i=0; i<MAX_PROCESS; i++)
    {
        SECURE_SEQUENCE[i] = -1;
        ALLOCATED[i] = 0;
    }
}

int Request_Query(int process, int resource[MAX_RESOURCE])

int Static_Query(int alcd)
{
    int all_allocated = 1;
    for (int i=0; i<MAX_PROCESS; i++)
        all_allocated &= ALLOCATED[i];

    if (all_allocated == 1)
        return 1;

    for (int i=0; i<MAX_PROCESS; i++)   // 遍历进程
    {
        if (ALLOCATED[i] == 0)  // 尚未分配的进程
        {
            int flag = 1;
            for (int j=0; j<MAX_RESOURCE; j++)
            {
                if (available[j] < NEED[i][j])  // 不可分配则遍历下一个
                {
                    flag = 0;
                    break;
                }
            }

            if (flag == 1)
            {
                ALLOCATED[i] = 1;
                SECURE_SEQUENCE[alcd] = i;

                if (Static_Query(alcd+1) == 0)

                SECURE_SEQUENCE[alcd] = -1;
                ALLOCATED[i] = 0;
            }
        }
    }
}

int main(void)
{
    Initialization();
}

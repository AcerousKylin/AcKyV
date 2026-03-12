#include <stdio.h>
#include <stdlib.h>

typedef struct Resource
{
    int alloc_A;
    int alloc_B;
    int alloc_C;
}R;

// 运算符“重载”函数
R add_Y2X(R x, R y)
{
   x.alloc_A += y.alloc_A;
   x.alloc_B += y.alloc_B;
   x.alloc_C += y.alloc_C;
   return x;
}

R minus_Y2X(R x, R y)
{
    x.alloc_A -= y.alloc_A;
    x.alloc_B -= y.alloc_B;
    x.alloc_C -= y.alloc_C;
    return x;
}

R copy_Y2X(R x, R y)
{
    x.alloc_A = y.alloc_A;
    x.alloc_B = y.alloc_B;
    x.alloc_C = y.alloc_C;
}

// 四个必需数据结构，最大需求矩阵、分配矩阵、需求矩阵和可用资源向量
R Max[5], Allocation[5], Need[5], Availible;
int safe = 0;   // 安全标识
// 安全序列及其标识量
int sequence[5], sequence_index, sequence_flag;

void Initialization(void)    // 多种情况下保存初始情况
{
    Max[0].alloc_A = 7, Max[0].alloc_B = 5, Max[0].alloc_C = 3;
    Max[1].alloc_A = 3, Max[1].alloc_B = 2, Max[1].alloc_C = 2;
    Max[2].alloc_A = 9, Max[2].alloc_B = 0, Max[2].alloc_C = 0;
    Max[3].alloc_A = 2, Max[3].alloc_B = 2, Max[3].alloc_C = 2;
    Max[4].alloc_A = 4, Max[4].alloc_B = 3, Max[4].alloc_C = 3;

    Allocation[0].alloc_A = 0, Allocation[0].alloc_B = 1, Allocation[0].alloc_C = 0;
    Allocation[1].alloc_A = 2, Allocation[1].alloc_B = 0, Allocation[1].alloc_C = 0;
    Allocation[2].alloc_A = 3, Allocation[2].alloc_B = 0, Allocation[2].alloc_C = 2;
    Allocation[3].alloc_A = 2, Allocation[3].alloc_B = 1, Allocation[3].alloc_C = 1;
    Allocation[4].alloc_A = 0, Allocation[4].alloc_B = 0, Allocation[4].alloc_C = 2;

    Need[0].alloc_A = 7, Need[0].alloc_B = 4, Need[0].alloc_C = 3;
    Need[1].alloc_A = 1, Need[1].alloc_B = 2, Need[1].alloc_C = 2;
    Need[2].alloc_A = 6, Need[2].alloc_B = 0, Need[2].alloc_C = 0;
    Need[3].alloc_A = 0, Need[3].alloc_B = 1, Need[3].alloc_C = 1;
    Need[4].alloc_A = 4, Need[4].alloc_B = 3, Need[4].alloc_C = 1;

    Availible.alloc_A = 3, Availible.alloc_B = 3, Availible.alloc_C = 2;

    safe = 0;
    for (int i=0; i<5; i++)
        sequence[i] = -1;
    sequence_index = 0;
    sequence_flag = 0;
}

int Safe_Query()    // 递归求安全序列
{
    for (int i=0; i<5; i++)
    {
        if (Need[i].alloc_A == 0 &&
            Need[i].alloc_B == 0 &&
            Need[i].alloc_C == 0)   // 若需求已被满足
            continue;              // 则跳过
        else
        {
            if (Availible.alloc_A >= Need[i].alloc_A &&
                Availible.alloc_B >= Need[i].alloc_B &&
                Availible.alloc_C >= Need[i].alloc_C )  // 可用资源足够分配
                Availible = add_Y2X(Availible, Need[i]);
            else
                continue;
            // 其他矩阵信息修改
            Allocation[i] = add_Y2X(Allocation[i], Need[i]);
            R temp = copy_Y2X(temp, Need[i]);
            Need[i].alloc_A = Need[i].alloc_B = Need[i].alloc_C = 0;

            // 生成安全序列并进行递归
            if (!sequence_flag)
                sequence[sequence_index++] = i;
            safe |= Safe_Query();   // 只要有一个安全序列即可
            if (!sequence_flag)
                sequence[sequence_index--] = -1;

            // 还原
            Availible = minus_Y2X(Availible, Need[i]);
            Allocation[i] = minus_Y2X(Allocation[i], Need[i]);
            Need[i] = copy_Y2X(Need[i], temp);
        }
    }

    // 判定此次完整递归是否安全
    int flag=1;
    for (int i=0; i<5; i++)
    {
        if (Need[i].alloc_A > 0 ||
            Need[i].alloc_B > 0 ||
            Need[i].alloc_C > 0)    // 如果仍然存在有需求的进程
            flag = 0;               // 则说明不安全
    }
    if (flag)               // 如果安全
        sequence_flag = 1;  // 安全序列成立
    return flag;            // 返回安全结果
}

int main(void)
{
    Initialization();
    safe |= Safe_Query();   // 启动递归并将最后结果进行合并
    printf("At T_0:\n");
    if (safe)
    {
        printf("Find a safe sequence!\n");
        printf("Sequence is:");
        for (int i=0; i<5; i++)
            printf("%d ", sequence[i]);
        printf("\n");
    }
    else
        printf("No safe sequence found.\n");



    // After P_1 requested (1, 0, 2)
    Initialization();
    printf("\nAfter P_1 requested (1, 0, 2):\n");
    Allocation[1].alloc_A += 1; Allocation[1].alloc_C += 2;
    Need[1].alloc_A -= 1; Need[1].alloc_C -= 2;
    Availible.alloc_A -= 1, Availible.alloc_C -= 2;
    safe |= Safe_Query();
    if (safe)
    {
        printf("Find a safe sequence!\n");
        printf("Sequence is:");
        for (int i=0; i<5; i++)
            printf("%d ", sequence[i]);
        printf("\n");
    }
    else
        printf("No safe sequence found.\n");



    // After P_4 requested (3, 3, 0)
    Initialization();
    printf("\nAfter P_4 requested (3, 3, 0):\n");
    Allocation[4].alloc_A += 3, Allocation[1].alloc_B += 3;
    Need[4].alloc_A -= 3, Need[4].alloc_B -= 3;
    Availible.alloc_A -= 3, Availible.alloc_B -= 3;
    safe |= Safe_Query();
    if (safe)
    {
        printf("Find a safe sequence!\n");
        printf("Sequence is:");
        for (int i=0; i<5; i++)
            printf("%d ", sequence[i]);
        printf("\n");
    }
    else
        printf("No safe sequence found.\n");
}

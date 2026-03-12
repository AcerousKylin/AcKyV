#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define cluster 3
#define L 20

int Page_Stream[L] =
{7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
int S[cluster];
int Missing_Pages;

void Initialization()
{
    for (int i=0; i<cluster; i++)
        S[i] = -1;
    Missing_Pages = 0;
}

void PrintS(int index)
{
    printf("-> %d => S[] ", index);
    for (int i=0; i<cluster; i++)
        printf("|%2d", S[i]);
    printf("|\n");
    return;
}

double Page_Fault_Rate(void)
{
    double PFR = (double)Missing_Pages/(double)L*100;
    printf("[Info] The page fault rate is %2.2f%%.\n", PFR);
    Missing_Pages = 0;
    return PFR;
}

void Optimal(void)  // 最佳置换算法
{
    printf("[Info] It's Optimal Algorithm is working down below.\n");
    for (int i=0; i<L; i++)
    {
        int page_missed = 1;
        for (int j=0; j<cluster; j++)   // 检查物理块中是否有流中输入的页
            if (Page_Stream[i] == S[j])
                page_missed = 0;        // 有则置缺页标识为0

        if (page_missed)                // 是否有缺页
        {
            // 首先检查物理块是否为空
            int has_empty_cluster = 0;  // 有空物理块标识
            for (int j=0; j<cluster; j++)
            {
                if (S[j] == -1) // 如果物理块是空
                {   // 优先填入物理块
                    S[j] = Page_Stream[i];
                    has_empty_cluster = 1;
                    break;
                }
            }

            // 若无空物理块
            if (!has_empty_cluster)
            {
                int appear_no_more = 1; // 流中不再出现标识
                // 块中各页在后继流中最近距离最远的相同页的流下标 和 将要替换的块的下标
                int furthest = i, replace_cluster_index = i;
                for (int j=0; j<cluster; j++)
                {
                    appear_no_more = 1;     // 每次循环开始，流中不再出现标识重新置1
                    for (int k=i+1; k<L; k++)
                    {
                        if (Page_Stream[k] == S[j])
                        {
                            if (furthest < k)   // 找到后继流中最近距离最远的相同页流中下标
                            {
                                furthest = k;
                                replace_cluster_index = j;  // 其对应块就是被替换块
                            }
                            appear_no_more = 0; // 如果在后继流中找到了相同的页，标识置0
                            break;
                        }
                    }
                    if (appear_no_more) // 如果有流中不再出现的页
                    {
                        S[j] = Page_Stream[i];  // 直接作为被替换块
                        break;
                    }
                }
                if (!appear_no_more)
                    S[replace_cluster_index] = Page_Stream[i];
                // printf("[Debug] furthest = %d, rci = %d\n", furthest, replace_cluster_index);
            }
            Missing_Pages++;
        }
        PrintS(Page_Stream[i]);
    }
}

void FIFO(void) // First In First Out - 先进先出置换算法
{
    printf("[Info] It's FIFO Algorithm is working down below.\n");
    int life[cluster] = {0, 0, 0};
    for (int i=0; i<L; i++)
    {
        int page_missed = 1;
        for (int j=0; j<cluster; j++)
            if (Page_Stream[i] == S[j])
                page_missed = 0;

        if (page_missed)
        {
            // 首先检查物理块是否为空
            int has_empty_cluster = 0;
            for (int j=0; j<cluster; j++)
            {
                if (S[j] == -1) // 如果物理块是空
                {   // 直接填入物理块，缺页+1
                    S[j] = Page_Stream[i];
                    has_empty_cluster = 1;
                    break;
                }
            }

            if (!has_empty_cluster)
            {
                int oldest = 0, oldest_index = 0;
                for (int j=0; j<cluster; j++)
                {
                    if (life[j] > oldest)
                    {
                        oldest_index = j;
                        oldest = life[j];
                    }
                }
                S[oldest_index] = Page_Stream[i];
                life[oldest_index] = 0;
            }
            Missing_Pages++;
        }
        PrintS(Page_Stream[i]);
        for (int j=0; j<cluster; j++)
            if (S[j] != -1)
                life[j]++;
    }
}

void LRU(void)  // Least Recently Used - 最近最久未使用置换算法
{
    printf("[Info] It's LRU Algorithm is working down below.\n");
    for (int i=0; i<L; i++)
    {
        int page_missed = 1;
        for (int j=0; j<cluster; j++)   // 检查物理块中是否有流中输入的页
            if (Page_Stream[i] == S[j])
                page_missed = 0;        // 有则置缺页标识为0

        if (page_missed)                // 是否有缺页
        {
            // 首先检查物理块是否为空
            int has_empty_cluster = 0;  // 有空物理块标识
            for (int j=0; j<cluster; j++)
            {
                if (S[j] == -1) // 如果物理块是空
                {   // 优先填入物理块
                    S[j] = Page_Stream[i];
                    has_empty_cluster = 1;
                    break;
                }
            }

            // 若无空物理块
            if (!has_empty_cluster)
            {
                // 块中各页在后继流中最近距离最远的相同页的流下标 和 将要替换的块的下标
                int nearest = i, replace_cluster_index = i;
                for (int j=0; j<cluster; j++)
                {
                    for (int k=i-1; k>-1; k--)
                    {
                        if (Page_Stream[k] == S[j])
                        {
                            if (nearest > k)   // 找到后继流中最近距离最远的相同页流中下标
                            {
                                nearest = k;
                                replace_cluster_index = j;  // 其对应块就是被替换块
                            }
                            break;
                        }
                    }
                }
                S[replace_cluster_index] = Page_Stream[i];
                // printf("[Debug] furthest = %d, rci = %d\n", furthest, replace_cluster_index);
            }
            Missing_Pages++;
        }
        PrintS(Page_Stream[i]);
    }
}

char * Algorithm(int index) // 输出对应顺序的算法字符串
{
    char *algo;
    switch(index)
    {
        case 0: algo = "Optimal\0";   break;
        case 1: algo = "FIFO\0";      break;
        case 2: algo = "LRU\0";       break;
        default:    "Error\0";
    }
    return algo;
}

int main(void)
{
    double page_fault_rates[3] = {0};

    Initialization();
    Optimal();
    page_fault_rates[0] = Page_Fault_Rate();

    Initialization();
    FIFO();
    page_fault_rates[1] = Page_Fault_Rate();

    Initialization();
    LRU();
    page_fault_rates[2] = Page_Fault_Rate();

    printf("\n[Info] The result is :");
    double max_PFR = 0.0, min_PFR = 100.0;
    int max_index = -1, min_index = -1;
    for(int i=0; i<3; i++)
    {
        if (max_PFR < page_fault_rates[i])
        {
            max_PFR = page_fault_rates[i];
            max_index = i;
        }

        if (min_PFR > page_fault_rates[i])
        {
            min_PFR = page_fault_rates[i];
            min_index = i;
        }
    }

    printf("%s has the lowest PFR，%s has the highest PFR.\n", Algorithm(max_index), Algorithm(min_index));

    return 1;
}

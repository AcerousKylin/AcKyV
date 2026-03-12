#include<bits/stdc++.h>
using namespace std;

const int N = 310;
int n;

struct mark
{   // 为了节省空间，不存与比较无关的数据
    int code;
    int chinese;
    int total;
};

mark s[N];

bool cmp(mark i, mark j)
{
    if (i.total == j.total)
    {
        if (i.chinese == j.chinese)
                return i.code < j.code;
        return i.chinese > j.chinese;
    }
    return i.total > j.total;
}

void quick_sort(int l, int r)
{
    if (l >= r)
        return;

    mark x = s[l+r+1>>1];
    int i=l-1, j=r+1;
    while (i < j)
    {
        while(cmp(s[++i], x));
        while(cmp(x, s[--j]));
        if (i < j)
            swap(s[i], s[j]);
    }

    quick_sort(l, i-1);
    quick_sort(i, r);
}

int main(void)
{
    scanf("%d", &n);

    for (int i=1; i<=n; i++)
    {
        s[i].code = i;

        int math, english;
        scanf("%d %d %d", &s[i].chinese, &math, &english);
        s[i].total = s[i].chinese + math + english;
    }

    quick_sort(1, n);

    for (int i=1; i<=5; i++)
        printf("%d %d\n", s[i].code, s[i].total);
    
    return 0;
}

/*

// 最优解
const int N = 500;
int n;

// 利用结构体，便于后面使用sort来编写对应题目的排序规则
// 也可以用vector-动态数组来存储
struct mark
{   // 为了节省空间，不存与比较无关的数据
    int code;
    int cns;
    int t;
};

// 排序规则，返回大于==升序，小于==降序
bool cmp(mark i, mark j)
{
    if (i.t == j.t)
    {
        if (i.cns == j.cns)
                return i.code < j.code;
        return i.cns > j.cns;
    }
    return i.t > j.t;
}

int main(void)
{
    scanf("%d", &n);

    // 使用结构体数组
    mark s[N];
    for (int i=1; i<=n; i++)
    {
        s[i].code = i;
        // 与比较无关的数据使用临时变量
        int mt, en;
        scanf("%d %d %d", &s[i].cns, &mt, &en);
        s[i].t = s[i].cns + mt + en;
    }

    // 使用自定义的排序规则，注意要比较的范围，结尾=尾部+1
    sort(s+1, s+n+1, cmp);

    for (int i=1; i<=5; i++)
        printf("%d %d\n", s[i].code, s[i].t);

    return 0;
}
*/

/*

// 错误范例：
// 1.二维数组难以代替结构体或动态数组等数据结构
// 2.手写快排自定义排序没有写完全
const int N = 500;
const int szof = 10 * sizeof(int);

int s[N][10];

int n;

void quick_sort(int l, int r)
{
    if (l >= r)
        return;
    
    int mid=l+r+1>>1;
    int x[5]={0, s[mid][1], s[mid][2], s[mid][3]};
    int i=l-1, j=r+1;

    while (i < j)
    {
        // 一旦重复元素出现在分界点就无法比较
        // 原因是这里两侧比较都不对，分层的比较应该直接写进这里
        while(s[++i][3] > x[3]);
        while(s[--j][3] < x[3]);

        // 每次排序、比较、互换数据浪费不少时间
        // 数字标识不是很直观，非常容易写错
        if (i < j && s[i][3] != s[j][3])
            for (int k=1; k<=3; k++)
                swap(s[i][k], s[j][k]);

        if (i < j && s[i][3] == s[j][3])
        {
            if (s[i][2] < s[j][2])
                for (int k=1; k<=3; k++)
                    swap(s[i][k], s[j][k]);

            else if (s[i][2] == s[j][2])
                if (s[i][1] > s[j][1])
                    for (int k=1; k<=3; k++)
                        swap(s[i][k], s[j][k]);
            else;
        }
    }

    quick_sort(l, i-1);
    quick_sort(i, r);
}

int main(void)
{
    scanf("%d", &n);

    for (int i=1; i<=n; i++)
    {
        int m, e;
        s[i][1] = i;
        scanf("%d %d %d", &s[i][2], &m, &e);
        s[i][3] = s[i][2] + m + e;
    }

    quick_sort(1, n);

    for (int i=1; i<=n; i++)
        printf("%d %d\n", s[i][1], s[i][3]);

    return 0;
}

*/
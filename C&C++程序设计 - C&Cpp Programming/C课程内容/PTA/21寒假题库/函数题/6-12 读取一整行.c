#include <stdio.h>

#define STR_LEN 20
#define N 5

void read_line(char str[], int n);

int main(void)
{
    char str[STR_LEN + 1];
    int length[N] = {0, 5, 10, 15, 20};
    
    // 分别测试最多输入 0 个、5 个、10 个、15 个和 20 个字符的情况
    for (int i = 0; i < N; i++) {
        read_line(str, length[i]);
        puts(str);
    }

    return 0;
}

/* 你的答案将出现在这里 */

void read_line(char str[], int n)
{
    int i;
    char temp;
    for (i=0; i<STR_LEN+1; i++)
        str[i] = '\0';
    for (i=0; i<n; i++)
    {
        scanf("%c", &temp);
        if (temp=='\n')
            break;
        str[i] = temp;
    }
    if (temp!='\n')
    {
        while(~scanf("%c", &temp))
            if (temp=='\n')
                break;
    }
    str[n] = '\0';
}
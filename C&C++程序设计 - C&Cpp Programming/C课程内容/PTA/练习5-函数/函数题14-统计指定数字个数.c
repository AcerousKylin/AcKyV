#include <stdio.h>

int CountDigit( int number, int digit );

int main()
{
    int number, digit;

    scanf("%d %d", &number, &digit);
    printf("Number of digit %d in %d: %d\n", digit, number, CountDigit(number, digit));

    return 0;
}

/* 你的代码将被嵌在这里 */

int CountDigit( int number, int digit )
{
    char num[20];
    sprintf(num, "%d", number);
    int i, count, len=strlen(num);
    for (i=0; i<=len; i++)
        if (digit+'0' == num[i])
            count++;
    return count;
}

/*
int CountDigit( int number, int digit )
{
    char num[20];
    sprintf(num, "%d", number); 
    // 将sprintf(char *buffer, "格式", 变量)是字符串格式化命令
    // 把格式化的数据写入某个字符串，对buffer字符数没有限制，存在溢出的危险
    // 可以控制精度、连接多个数值/字符串、动态指定、打印地址、返回长度
    int i, count, len=strlen(num);
    for (i=0; i<=len; i++)
        if (digit+'0' == num[i])
            count++;
    return count;
}
*/
//分离标准写法
#include<stdio.h>
int main(void)
{
    int amount, target, mark, flag=0;
    scanf("%d %d", &amount, &target);
    int numbers[amount];
    for (mark=0; mark<amount; mark++)
        scanf("%d", &numbers[mark]);
    for (mark=0; mark<amount; mark++)
    {
        if (numbers[mark]==target)
        {
            printf("%d", mark);
            flag = 1;
        }
    }
    if (flag==0)
        printf("Not Found");
    return 0;
}

//无数组写法
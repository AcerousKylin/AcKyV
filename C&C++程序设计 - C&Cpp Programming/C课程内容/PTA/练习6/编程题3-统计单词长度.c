#include<stdio.h>
#include<string.h>
int main(void)
{
    char ch[50]; int flag=0;
    while (~scanf("%s", ch))
    {
        printf("%d ", strlen(ch));
        flag = 1;
    }
    if (flag==0)
        printf("0 ");
    return 0;
}
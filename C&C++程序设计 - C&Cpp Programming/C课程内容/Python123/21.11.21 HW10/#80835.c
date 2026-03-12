//输入一个少于80字符、以回车为结尾的字符串
//判断该字符串是否为回文（中心对称）
//如果是，输出YES，否则输出NO
#include<stdio.h>
int main(void)
{
    char Cycle[100]; int i, o, point, flag=1;
    gets(Cycle);
    for (i=0; Cycle[i]!='\0'; i++);
    for (o=1; i/2-o>=0; o++)
    {
        if (Cycle[i/2-o]!=Cycle[i/2+o])
        {
            flag = 0;
            break;
        }
    }
    /*
    for()
    */
    if (flag==0)
        printf("No");
    if (flag==1)
        printf("Yes");
    return 0;
}
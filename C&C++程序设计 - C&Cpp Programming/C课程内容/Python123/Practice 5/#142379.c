 //输出一串以#结束的字符，依次输出每个字符及其ASCII码值
#include<stdio.h>
int main(void)
{
    char ch;
    while(ch!='#')
    {
        ch = getchar();
        if (ch!='#')
            printf("%c-%d\n", ch, ch);
    }
    return 0;
}

//while版
#include<stdio.h>
int main()
{
    char ch;
    while((ch=getchar())!='#')
        printf("%c-%d\n",ch,ch);
    return 0;
}
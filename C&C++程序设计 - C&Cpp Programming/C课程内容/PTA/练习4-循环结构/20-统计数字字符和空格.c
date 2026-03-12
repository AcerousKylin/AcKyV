//输入一行字符，统计其中数字字符、空格和其他字符的个数
#include<stdio.h>
int main(void)
{
    int n, blank, digit, other;
    char ch;
    blank = digit = other = 0;
    do
    {
        ch = getchar();
        switch (ch)
        {
            case ' ' :
                blank++;
                break;
            case '0' :
            case '1' :
            case '2' :
            case '3' :
            case '4' :
            case '5' :
            case '6' :
            case '7' :
            case '8' :
            case '9' :
                digit++;
                break;
            default :
                other++;
        }
    }while (ch!='\n');
    printf("blank = %d, digit = %d, other = %d", blank, digit, other-1);
    return 0;
}

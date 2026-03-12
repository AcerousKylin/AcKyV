#include<stdio.h>
int main(void)
{
    /*char ch = getchar();
    if (ch<=96) printf("%c", ch+32);
    else if (ch>=97) putchar(ch);
    else;
    return 0;*/
    char ch;
    scanf("%c", &ch);
    if (ch<=96) printf("%c", ch+32);
    else if (ch>=97) printf("%c", ch-32);
    else;
    return 0;
}

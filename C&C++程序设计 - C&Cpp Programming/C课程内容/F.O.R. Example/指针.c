//字符指针和字符串输出
#include<stdio.h>
int main(void)
{
    char *p;
    for(p="ABCDE" ;*p!='\0';p++) 
        printf("%s\n",p);
    return 0; 
}
/*输出
ABCDE
BCDE
CDE
DE
E
*/

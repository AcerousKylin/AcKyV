/*变换规则是：
将明文中的所有英文字母替换为字母表中的后一个字母
同时将小写字母转换为大写字母，大写字母转换为小写字母
例如，字母a->B、b->C、…、z->A、A->b、B->c、…、Z->a
*/
#include<stdio.h>
#include<string.h>
int main(void)
{
    char a[100], *p=a; int i;
    gets(a);
    for (i=0, p=a; i<strlen(a); i++, p++)
    {
        if (*p>='A' && *p<='Y')
            *p += 33;
        else if (*p>='a' && *p<='y')
            *p -= 31;
        else if (*p=='Z')
            *p = 'a';
        else if (*p=='z')
            *p = 'A';
   }
   puts(a);
   return 0;
}
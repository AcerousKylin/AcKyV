//#143115字符串复制（函数&指针）
#include<stdio.h>
int str_copy(char *d,char *s)
{
    while(*s!='\0')
    {
        *d++ = *s++;
    }
    *d='\0';
}
int main(void)
{
    char pa[81];
    char pb[81];
    gets(pa); 
    str_copy(pb,pa);
    printf("%s",pb);
    return 0; 
}

//#143116字符串连接（函数&指针）
#include<stdio.h>
int str_cat(char *d,char *s)
{
    while(*d!='\0')
        d++;
    while(*s!='\0')
        *d++ = *s++;
}
int main(void)
{
    char pa[81];
    char pb[81];
    char pc[81]="";
    gets(pa);
    gets(pb); 
    str_cat(pc,pa);
    str_cat(pc,pb);
    printf("%s",pc);
    return 0; 
}

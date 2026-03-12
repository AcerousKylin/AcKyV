#include<stdio.h>
#include<string.h>

int DeleteWords(char s1[],char s2[]) ;

int main()
{
    char s1[101],s2[21];
    gets(s1);
    gets(s2);
    if(DeleteWords(s1,s2))
        puts(s1);
    else
        printf("No delete!\n");
    return 0;
}
/* 请在这里填写答案 */

int DeleteWords(char s1[],char s2[])
{
    int n, i, count=0;
    char *p1, *p2;
    for (n=0; s1[n]!='.'; n++); // 如果没有;为什么甚至连No Delete都无法输出了
    p1 = &s1[n] - strlen(s2);
    p2 = s2;
    while (*p1!='.')
        if (*(p1++)!=*(p2++))
            return 0;
    p1 = &s1[n];
    while(count<strlen(s2))
        if (*(--p1)==' ')
            count++;
    *p1 = '.'; *(p1+1)='\0';
    return 1;
}
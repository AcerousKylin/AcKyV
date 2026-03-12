#include<stdio.h>
#include<string.h>
int main(void)
{
    char ch[500]={0}; char *pc;
    gets(ch);
    for (pc=ch; pc<ch+strlen(ch); pc++)
    {
        if (pc==ch && (*pc>='a' && *pc<='z') )
            *pc -= 32;
        if (*pc==' ' && (*(pc+1)>='a' && *(pc+1)<='z'))
            *(pc+1) -= 32;
    }
    puts(ch);
    return 0;
}
/*1001
#include<stdio.h>
#define N 1001
int main(void)
{
    char ch[N]; int i, j; int flag[N];
    gets(ch);
    for (i=0; ch[i]!='\0'; i++)
    {
        if (ch[i]>='0' && ch[i]<='9')
            flag[i] = 1;
        if ((ch[i]>='A' && ch[i]<='Z')||(ch[i]>='a' && ch[i]<='z'))
            flag[i] = 2;
    }
    for (j=0; j<i-1; j++)
    {
        if (flag[j]!=flag[j+1])
        {
            printf("mixed\n");
            return 0;
        }
    }
    if (flag[0]==2)
        printf("character\n");
    if (flag[0]==1)
        printf("digit\n");
    return 0;
}
*/

//1006
#include<stdio.h>
int mystrcmp(char *d, char *p)
{
    for (int i=0;*(d+i)!='\0'||*(p+i)!='\0' ; i++)
    {
        if (*(d+i) == *(p+i))
            continue;
        else
        {
            if (*(d+i)>*(p+i))
                return 1;
            else
                return -1;
        }
    }
    return 0;
}
int main(void)
{
    char s1[51],s2[51];
    int k;
    gets(s1);
    gets(s2);
    k = mystrcmp(s1, s2); 
    if (k>0)
        printf("%s > %s\n", s1, s2);
    else if (k==0)
        printf("%s = %s\n", s1, s2);
    else
        printf("%s < %s\n", s1, s2);
    return 0;
}
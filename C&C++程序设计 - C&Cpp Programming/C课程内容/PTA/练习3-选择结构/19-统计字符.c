/*
#include<stdio.h>
int main(void)
{
    int count, n, ltr, blk, dgt, odr;
    char ch;
    ltr = blk = dgt = 0;
    scanf("%d", &n);
    getchar();
    for (count=0; count<n; count++)
    {
        ch = getchar();
        if (ch>=48&&ch<=57)
            dgt++;
        else if (ch>=65&&ch<=90)
            ltr++;
        else if (ch>=97&&ch<=122)
            ltr++;
        else if (ch==' ')
            blk++;
        else if (ch=='\n')
            blk++;
        else
            odr++;
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d", ltr, blk, dgt, odr);
    return 0;
}
*/
#include<stdio.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    getchar();//此处的getchar()作用是吃掉回车 否则for循环第一个%c会读入回车，导致答案错误
    int s1=0,s2=0,s3=0,s4=0;
    for(int i=0;i<n;i++)
    {
        char x;
        scanf("%c",&x);
        if((x>='a'&&x<='z')||(x>='A'&&x<='Z')) s1++;
        else if(x==' '||x=='\n') s2++;
        else if(x>='0'&&x<='9') s3++;
        else s4++;
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d",s1,s2,s3,s4);
    return 0;
}

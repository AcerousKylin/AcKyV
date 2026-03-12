#include<stdio.h>
int main(void)
{
    int i, l, s, d, o;
    l = s = d = o = 0;
    for(i=0; i<10; i++)
    {
        char temp;
        scanf("%c", &temp);
        if ((temp>='A' && temp<='Z') || (temp>='a' && temp<='z'))
            l++;
        else if (temp==' ' || temp=='\n')
            s++;
        else if (temp>='0' && temp<='9')
            d++;
        else
            o++;
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d", l, s, d, o);
    return 0;
}
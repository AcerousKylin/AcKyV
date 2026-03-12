#include <stdio.h>
#define MAXS 20

void f( char *p );
void ReadString( char *s ); /* 由裁判实现，略去不表 */

int main()
{
    char s[MAXS];

    ReadString(s);
    f(s);
    printf("%s\n", s);

    return 0;
}

/* 你的代码将被嵌在这里 */

//指针前后互换版本（WIP）
void f( char *p )
{
    char *pc=p, temp;
    int length=0, i;
    while (*pc!='\0')
    {
        length++;
        pc++;
    }
    for(pc=p, i=0; i<length/2; pc++, i++)
    {
        temp = *pc;
        *pc = p[length-i];
        p[length-i] = temp;
    }
}

//指针数组前后夹逼
void f( char *p )
{
    int i=0, front=0, back, length=1, temp;
    while(p[i]!='\0')
        length++;
    for (front=0, back=length-1; front<=back; front++, back--)
    {
        temp = p[front];
        p[front] = p[back];
        p[back] = temp;
    }
    return ;
}
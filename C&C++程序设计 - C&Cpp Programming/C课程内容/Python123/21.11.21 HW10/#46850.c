//逆序输出10个数字
//函数版
#include<stdio.h>
int n[10];
void Reverse(void)
{
    int i;

}
int main(void)
{
    int i;
    Reverse();
    for (i=9; i>=0; i--)
    {
        if (i!=9) printf(" ");
        printf("%d",n[i]);
    }
    return 0;
}

//简易版
#include<stdio.h>
int main(void)
{
    int i; int n[10];
    for (i=0; i<=9; i++)
        scanf("%d", &n[i]);
    for (i=9; i>=0; i--)
    {
        if (i!=9) printf(" ");
        printf("%d",n[i]);
    }
    return 0;
}
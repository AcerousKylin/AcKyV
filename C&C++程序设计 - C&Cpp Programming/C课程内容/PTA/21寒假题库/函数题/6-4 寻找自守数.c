/*
所谓自守数(也称守形数)
是指其平方数的低位部分恰为该数本身的自然数。
例如：25*25=625,因此25是自守数。
注：0 和 1 也算自守数。
*/

#include <stdio.h>

int IsAutomorphic(int x);
void FindAutomorphic(int lower, int upper);

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    FindAutomorphic(a, b);
    return 0;
}

......

/* 你提交的代码将被嵌在这里 */

int MyAutomorphic(int x) // 手写版本
{
    int ten=10, i, temp=0;
    if (x==0 && x==1)
        return 1;
    if (x<0)
        return 0;
    for(i=0; i<6; i++)
    {
        if (x/ten==0)
            break;
        ten *= 10;
    }
    temp = (x*x) % ten;
    if (temp==x)
        return 1;
    if (temp!=x)
        return 0;
}
void FindAutomorphic(int lower, int upper)
{
    int i, flag=0;
    for (i=lower; i<=upper; i++)
    {
        if (IsThisAutomorphic(i))
        {
            printf("%d\n", i);
            flag = 1;
        }
    }
    if (!flag)
        printf("None");
}
//数组a中的10个数按升序排列。
//从键盘输入一个待插入数key，将其插入到数组中，使数组依然保持升序。
/*
#include <stdio.h>
int main (void)
{
    int n[15]; int s[15];
    int key, count, i=1; n[0]=-32768;
    for (count=1; count<=10; count++)
        scanf("%d", &n[count]);
    scanf("%d", &key);
    for (count=1; count<=11; count++)
    {
        if (key>n[count-1] && key<n[count])
        {
            s[count] = key; count++;
        }
        s[count]=n[i];
        i++;
    }
    for (count=1; count<=11; count++)
        printf("%d ", s[count]);
    return 0;
}
*/

#include <stdio.h>
int main (void)
{
    int n[50];
    int key, count, i=1; n[0]=-32768;
    for (count=1; count<=10; count++)
        scanf("%d", &n[count]);
    scanf("%d", &key);
    for (count=11; count<=1; count++)
    {
        if (key>n[count-1])
        {
            s[count] = key; count++;
        }
        s[count]=n[i];
        i++;
    }
    printf("%d", n[1]);
    for (count=2; count<=11; count++)
        printf(" %d", s[count]);
    return 0;
}
/*
#include<stdio.h>
int a[15];
int main(void)
{
    for (int i=1; i<=10; ++i)
    {
        scanf("%d",&a[i]);
    }
    int index=11;
    int x;
    scanf("%d",&x);
    for (int i=1; i<=10; ++i)
    {
        if(a[i]>x)
        {
            index=i;
            break;
        }
    }

    if(index==11)
    {
        for(int i=1;i<=10;++i)
        {
            printf("%d ",a[i]);
        }
        printf("%d\n",x);
    }
    else
    {
        for(int i=11;i>=index;--i)
        {
            a[i]=a[i-1];
        }
        a[index]=x;
        for(int i=1;i<=11;++i)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    return 0;
}
*/
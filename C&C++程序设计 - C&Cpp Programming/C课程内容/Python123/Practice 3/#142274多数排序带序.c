#include<stdio.h>
int main(void)
{
    int n1, n2, n3, n4, n5, max, n=1;
    scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);
    if (n1<n2)
    {
        max=n2; n2=n1; n1=max; //存大数，换顺序
    }
    if (n1<n3)
    {
        max=n3; n3=n1; n1=max;
    }
    if (n1<n4)
    {
        max=n4; n4=n1; n1=max;
    }
    if (n1<n5)
    {
        max=n5; n5=n1; n1=max;
    }

    if (n2<n3)
    {
        max=n3; n3=n2; n2=max;
    }
    if (n2<n4)
    {
        max=n4; n4=n2; n2=max;
    }
    if (n2<n5)
    {
        max=n5; n5=n2; n2=max;
    }

    if (n3<n4)
    {
        max=n4; n4=n3; n3=max;
    }
    if (n3<n5)
    {
        max=n5; n5=n3; n3=max;
    }

    if (n4<n5)
    {
        max=n5; n5=n4; n4=max;
    }//解决个别，默认不管
    printf("%d - %d\n", n, n1);
    if (n1!=n2)
        printf("%d - %d\n", n=2, n2);
    else printf("%d - %d\n", n, n2);
    if (n2!=n3)
        printf("%d - %d\n", n=3, n3);
    else printf("%d - %d\n", n, n3);
    if (n3!=n4)
        printf("%d - %d\n", n=4, n4);
    else printf("%d - %d\n", n, n4);
    if (n4!=n5)
        printf("%d - %d\n", n=5, n5);
    else printf("%d - %d\n", n, n5);
    return 0;
}
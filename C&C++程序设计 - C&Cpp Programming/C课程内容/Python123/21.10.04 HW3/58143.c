#include<stdio.h>
int main(void)
{

    int n, m;
    scanf("%d",&n);
    m = n % 2;
    switch (m)
    {
        case 0 :
            printf("EVEN");
            break;
        case 1 :
            printf("ODD");
            break;
        default :
            printf("ERROR");
            break;
    }

    /*
    int n, m;
    scanf("%d",&n);
    m = n % 2;
    if (m==0)
        printf("EVEN");
    else printf("ODD");
    */
    /*
    int n, m;
    char ch;
    scanf("%d",&n);
    m = n % 2;
    ch = m==0?'E':'O';
    printf("%c",ch);
    */
    return 0;
}

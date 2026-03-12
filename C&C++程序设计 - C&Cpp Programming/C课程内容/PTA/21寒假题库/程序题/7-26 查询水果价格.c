#include<stdio.h>
int main(void)
{
    printf("[1] apple\n");
    printf("[2] pear\n");
    printf("[3] orange\n");
    printf("[4] grape\n");
    printf("[0] exit\n");
    int i, o, item;
    for (i=0; i<5; i++)
    {
        scanf("%d", &item);
        if (item==0)
            exit(0);
        else if (item==1)
            printf("price = 3.00\n");
        else if (item==2)
            printf("price = 2.50\n");
        else if (item==3)
            printf("price = 4.10\n");
        else if (item==4)
            printf("price = 10.20\n");
        else
            printf("price = 0.00\n");
    }
    return 0;
}
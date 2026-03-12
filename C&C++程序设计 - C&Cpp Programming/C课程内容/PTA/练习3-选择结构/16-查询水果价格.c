#include<stdio.h>
int main(void)
{
    int a, b, c, d, e;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    printf("[1] apple\n");
    printf("[2] pear\n");
    printf("[3] orange\n");
    printf("[4] grape\n");
    printf("[0] exit\n");
    switch (a)
    {
        case 0 :
            return 0;
        case 1 :
            printf("price = 3.00\n");
            break;
        case 2 :
            printf("price = 2.50\n");
            break;
        case 3 :
            printf("price = 4.10\n");
            break;
        case 4 :
            printf("price = 10.20\n");
            break;
        default :
                printf("price = 0.00\n");
                return 0;
    }
    switch (b)
    {
        case 0 :
            return 0;
        case 1 :
            printf("price = 3.00\n");
            break;
        case 2 :
            printf("price = 2.50\n");
            break;
        case 3 :
            printf("price = 4.10\n");
            break;
        case 4 :
            printf("price = 10.20\n");
            break;
        default :
                printf("price = 0.00\n");
                return 0;
    }
    switch (c)
    {
        case 0 :
            return 0;
        case 1 :
            printf("price = 3.00\n");
            break;
        case 2 :
            printf("price = 2.50\n");
            break;
        case 3 :
            printf("price = 4.10\n");
            break;
        case 4 :
            printf("price = 10.20\n");
            break;
        default :
                printf("price = 0.00\n");
                return 0;
    }
    switch (d)
    {
        case 0 :
            return 0;
        case 1 :
            printf("price = 3.00\n");
            break;
        case 2 :
            printf("price = 2.50\n");
            break;
        case 3 :
            printf("price = 4.10\n");
            break;
        case 4 :
            printf("price = 10.20\n");
            break;
        default :
                printf("price = 0.00\n");
                return 0;
    }
    switch (e)
    {
        case 0 :
            return 0;
        case 1 :
            printf("price = 3.00\n");
            break;
        case 2 :
            printf("price = 2.50\n");
            break;
        case 3 :
            printf("price = 4.10\n");
            break;
        case 4 :
            printf("price = 10.20\n");
            break;
        default :
                printf("price = 0.00\n");
                return 0;
    }
    return 0;
}

/* 正确解法1
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
    */

    /*
    int n;
    int count=0;
    printf("[1] apple\n");
    printf("[2] pear\n");
    printf("[3] orange\n");
    printf("[4] grape\n");
    printf("[0] exit\n");
    while (count<5)
    {
        scanf("%d", &n);
        count++;
        if (n==0)
            return 0;
        else if (n>0&&n<5)
        {
            switch (n)
            {
            case 1 :
                printf("price = 3.00\n");
                break;
            case 2 :
                printf("price = 2.50\n");
                break;
            case 3 :
                printf("price = 4.10\n");
                break;
            case 4 :
                printf("price = 10.20\n");
                break;

            }
        }
        else
            printf("price = 0.00\n");
    }
*/

/* 正确解法2
#include<stdio.h>
int main(void)
{
    int n;
    int count;
    printf("[1] apple\n");
    printf("[2] pear\n");
    printf("[3] orange\n");
    printf("[4] grape\n");
    printf("[0] exit\n");
    for (count = 0; count<5; count++)
    {
        scanf("%d", &n);
        if (n==0)
            return 0;
        else if (n>0&&n<5)
        {
            switch (n)
            {
            case 1 :
                printf("price = 3.00\n");
                break;
            case 2 :
                printf("price = 2.50\n");
                break;
            case 3 :
                printf("price = 4.10\n");
                break;
            case 4 :
                printf("price = 10.20\n");
                break;

            }
        }
        else
            printf("price = 0.00\n");
    }
   
    return 0;
}
*/
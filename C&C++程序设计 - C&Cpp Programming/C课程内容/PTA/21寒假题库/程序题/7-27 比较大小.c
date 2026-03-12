#include<stdio.h>
int main(void)
{
    int number[100];
    int i, j;
    for (i=0; i<3; i++)
        scanf("%d", &number[i]);
    for (i=0; i<3; i++)
    {
        for (j=i+1; j<3; j++)
        {
            if (number[i]>number[j])
            {
                int temp;
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
    }
    for (i=0; i<3; i++)
    {
        printf("%d", number[i]);
        if (i!=2)
            printf("->");
    }
    return 0;
}
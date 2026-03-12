#include<stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int numbers[n], i, j, temp;
    for (i=0; i<n; i++)
        scanf("%d", &numbers[i]);
    for (i=0; i<n; i++)
    {
        for (j=i+1; j<n; j++)
        {
            if (numbers[i]<numbers[j])
            {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
    for (i=0; i<n; i++)
    {
        printf("%d", numbers[i]);
        if (i!=n-1)
            printf(" ");
    }
    return 0;
}
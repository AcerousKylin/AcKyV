#include<stdio.h>
void Shuffle( int p[], int i, int j )
{
    int temp;
    temp = p[i];
    p[i] = p[j];
    p[j] = temp;
}
int main(void)
{
    int i, j, k;
    int deck[54], order[54];
    scanf("%d", &k);
    for (i=0; i<54; i++)
    {
        deck[i] = i;
        scanf("%d", order[i]);
    }
    for (i=0; i<k; i++)
        for (j=0; j<54; j++)
            Shuffle(deck, j, order[j]);
    for (i=0; i<54; i++)
    {
        if (deck[i]<13)
            printf("S%d", deck[i]+1);
        if (deck[i]>=13 && deck[i]<26)
            printf("H%d", deck[i]-13+1);
        if (deck[i]>=26 && deck[i]<39)
            printf("C%d", deck[i]-26+1);
        if (deck[i]>=39 && deck[i]<52)
            printf("D%d", deck[i]-39+1);
        if (deck[i]==52 || deck[i]==53)
            printf("J%d", deck[i]-52+1);
        if (i!=53)
            printf(" ");
    }
    return 0;
}
#include<stdio.h>
int main(void)
{
    int head, foot, chic, rubbit;
    scanf("%d %d", &head, &foot);
    rubbit = 0.5*(foot-2*head);
    chic = head - rubbit;
    printf("%d %d", chic, rubbit);
}
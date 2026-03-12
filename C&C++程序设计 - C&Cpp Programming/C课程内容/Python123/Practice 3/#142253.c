#include<stdio.h>
int main(void)
{
    int today, pass, that;
    scanf("%d %d", &today, &pass);
    that = today + pass;
    if (that>7)
        that -= 7;
    printf("%d", that);
    return 0;
}
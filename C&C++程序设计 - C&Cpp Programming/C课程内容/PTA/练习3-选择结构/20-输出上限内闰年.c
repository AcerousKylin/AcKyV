#include<stdio.h>
int main(void)
{
    int iyear, cyear;
    scanf("%d", &iyear);
    if (iyear<=2000|iyear>2100)
        printf("Invalid year!");
    else if (iyear<2004)
        printf("None");
    else
    {
        for (cyear=2001; cyear<=iyear; cyear++)
        {
            if (cyear<iyear&&(cyear%4==0&&cyear%100!=0|cyear%400==0))
            {
                printf("%d\n", cyear);
            }
            else if (cyear<=iyear&&(cyear%4==0&&cyear%100!=0|cyear%400==0))
                printf("%d", cyear);
            else;
        }
    }
    return 0;
}

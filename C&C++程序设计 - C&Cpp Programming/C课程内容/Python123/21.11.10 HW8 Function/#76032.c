//输出区间所有闰年函数版
#include <stdio.h>
int isLeapYear( int year )
{
    if ((year%4==0 && year%100!=0) || year%400==0)
        return 1;
    return 0;
}
int main(void)
{
    int year1, year2, year;
    scanf("%d,%d", &year1, &year2);
    for (year=year1; year<=year2; year++)
    {
        if (isLeapYear(year)==1)
            printf("%6d", year);
    }
    return 0;
}
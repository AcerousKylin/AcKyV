//输入年月日，输出这是这年的第几天
#include<stdio.h>
int main(void)
{
    int year, month, day, number=0;
    scanf("%d %d %d", &year, &month, &day);
    switch (month)
    {
        case 12 : number += 31;
        case 11 : number += 30;
        case 10 : number += 31;
        case  9 : number += 30;
        case  8 : number += 31;
        case  7 : number += 31;
        case  6 : number += 30;
        case  5 : number += 31;
        case  4 : number += 30;
        case  3 : number += 31;
        case  2 : 
            if ((year%4==0&&year%100!=0)||year%400==0)
                number += 29;
            else
                number += 28;
            break;
        default :
            number=day;
            printf("%d", day);
            return 0;
    }
    number += day;
    printf("%d", number);
    return 0;
}
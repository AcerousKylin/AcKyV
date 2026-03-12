#include <stdio.h>
# include <math.h>

unsigned int reverse( unsigned int number );

int main()
{
    unsigned int n;

    scanf("%u", &n);
    printf("%u\n", reverse(n));

    return 0;
}


/* 请在这里填写答案 */

unsigned int reverse(unsigned int number)
{
    int flag = 1;
    if (number<0)
    {
        flag = -1;
        number = -number;
    }
    else if (number<10)
        return number;
    int count = 0, temp = number;
    while (temp>0)
    {
        temp /= 10;
        count++;
    }
    return flag*((number%10)*pow(10,count-1)+reverse(number/10));
}
//对于给定的正整数N，求它的位数及其各位数字之和
#include<stdio.h>
#include<math.h>
int main(void)
{
    int n, sum=0, number, bit=0;
    scanf("%d", &n);
    if (n==0) printf("1, %d", n);
    while (n!=0)
    {
        number = n%10; //将最低位取出
        sum += number; //最低位存储
        n /= 10;       //减小数据规模数据
        bit++;         //进位
    }
    printf("%d %d", bit, sum);
    return 0;
}

//用格雷格里公式求pi的近似值
//当某一项的绝对值小于10^-6时停止，while版
#include<stdio.h>
#include<math.h>
int main(void)
{
    double pi=0.0, n=2.0, item=1.0;
    while (fabs(item)>=1e-6)
    {
        pi += item;
        item=1.0*(pow(-1, n+1)/(2*n-1));
        n++;
    }
    printf("%.6f", 4.0*pi);
    return 0;
}

//写法2
#include<stdio.h>
#include<math.h>
int main(void)
{
    int i=1;
    double j=1, pi4=0.0;
    while(1.0/(2*i-1)>1e-6)
    {
        j = pow(-1, (i+1)))*1.0/(2*i-1);
        pi4 += j; i++;
    }
    printf("%.6f", 4*pi4);
    return 0;
}

//算法3
#include <stdio.h>
#include <math.h>
int main()
{
    double n,sign =1.0;
    int i=0;
    double sum =0.0;
    scanf("%lf",&n);
    while(fabs(i)<2*n-1)
    {
        sum = sum+sign/i;
        sign = -sign;
        i += 2;
    }
    printf("%f\n",sum*4);
    return 0;
}
/*总结：
每一项的计算方法有：
正负的控制：直接写在sum的公式里；单独用sign控制
分母的通项：简单地单独增加分母；直接用循环计数计算
*/

//for版，输入所需计算项数
#include<stdio.h>
int main(void)
{
    int i, n; double item, pi=0.0;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        if (i%2==0)
            item = -1.0/(2*i-1);
        if (i%2==1)
            item = 1.0/(2*i-1);
        pi += item;
    }
    printf("%lf", pi*4);
    return 0;
}
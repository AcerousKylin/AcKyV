#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main(void)
{  
    double a, b;
    scanf("%lf%lf",&a,&b); /*输入两个实数，格式说明符%lf代表double类型*/
    printf("sin(%lf)=%lf\n",a,sin(a*PI/180));/*a为角度，则a*PI/180为弧度*/
    //  正弦函数
     printf("cos(%lf)=%lf\n",a,cos(a*PI/180));
    //  余弦函数
    printf("exp(%lf)=%lf\n",a,exp(a));
    // e的指数函数
    printf("log(%lf)=%lf\n",a,log(a));
    // 对数函数
    printf("log10(%lf)=%lf\n",a,log10(a));
    // 底数为10的对数函数
    printf("pow(%lf,%lf)=%lf\n",a,b,pow(a,b));
    // 指数函数
    return 0;
}
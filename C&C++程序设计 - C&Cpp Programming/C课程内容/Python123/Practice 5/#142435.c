/*二分法求方程近似根的基本思想是：
1.设定初始有根区间 [a,b];
2.找到区间的中点x=(a+b)/2;
3.如果|f(x)|< ε,则认为该点x就是方程的近似根（ε是一个极小值）;
4.如果f(x)与f(a)同号，则把x赋值给a;否则把x赋值给b;
5.转向步骤2开始下一次迭代。
已知函数 f(x)=x5−2x4+x2−3在区间[0,2]内与x轴肯定有交点，即方程f(x)=0有根，
用二分法求出方程在区间[0,2]内的一个近似根。算法中的ε取值由输入得到*/
#include<stdio.h>
double f( double x )
{
    return x*x*x*x*x - 2 * x*x*x*x + x*x - 3;
}
int main(void)
{
    double a=0.0, b=2.0, x=1.0, edge;
    scanf("%lf", &edge);
    while (fabs(f(x))>=edge)
    {
        x = (a+b)/2;
        if ( (f(x)>=0 && f(a)>=0) || (f(x)<0 && f(a)<0) )
            a = x;
        else
            b = x;
    }
    printf("%.8f", x);
    return 0;
}
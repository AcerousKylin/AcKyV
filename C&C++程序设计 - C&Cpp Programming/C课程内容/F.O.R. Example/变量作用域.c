//例1
#include<stdio.h>
int main(void)
{
    int a, b;
    a=5; b=8;
    printf("%d,%d\n", a, b);
    {
        a+=2; b+=5;
        printf("%d,%d\n", a, b);
        int a, k;
        a=15; b=18; //局部的a，外部a不受影响，外部无法调用该a
        printf("%d,%d\n", a, b);
    }
    a+=2; b+=5; //因此此处调用的a是外部的a
    printf("%d,%d\n", a, b);
    return 0;
}
//结果：
/*
5,8
7,13
15,18
9,23
*/

//例2
#include<stdio.h>
#define PI 3.14159265 //全局常量
void fun(double r)
{
    extern double l,s,v;     //全局变量的说明 
    l=2*PI*r;
    s=PI*r*r;
    v=(4.0/3.0)*PI*r*r*r;
}
double l,s,v;                //全局变量的定义 
int main(void)
{
    double r;  
    scanf("%lf",&r);
    fun(r);
    printf("L=%lf S=%lf V=%lf",l,s,v);
    return 0;
}

//例3
#include<stdio.h>
int x=11,y=12,z=13; //全局变量定义
void fun(void)
{
    int x=21,y=22; //局部变量定义，函数结束后释放
    printf("x=%d,y=%d,z=%d\n",x,y,z);
}
int main(void)
{ 
    {
      int y=32; //局部变量定义，局部执行结束后释放
      printf("x=%d,y=%d,z=%d\n",x,y,z);
      fun();
    }
    printf("x=%d,y=%d,z=%d\n",x,y,z);
    return 0;
}

//例4
#include<stdio.h>
long next(long n)
{
    static long s=0; //s初始化为0，即此后执行函数后不再赋值
    if(n%2==1)
        n = n*3+1;
    else
        n = n/2;
    s++;
    printf("Times of %ld is %ld.\n", s, n);
    return n;
}
int main(void)
{
    long n;
    scanf("%ld",&n);
    while(n!=1)
    { 
        n = next(n);
    }
    return 0;
}
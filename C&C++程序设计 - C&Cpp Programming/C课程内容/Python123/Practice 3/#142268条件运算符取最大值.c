//if-else版本
#include<stdio.h>
int main(void)
{
    int a, b, c, max;
    scanf("%d %d %d", &a, &b, &c);
    if (a>=b)
    {
        if (c>=a) max=c;
        else max=a;
    }
    else
    {
        if (c>=b) max=c;
        else max=b;
    }
    printf("%d", max);
    return 0;
}

//条件运算符版本
/*
#include<stdio.h>
int main(){
    int a,b,c,m;
    scanf("%d%d%d",&a,&b,&c);
    m=(a>b)?a:b; //条件成立执行冒号左侧
    m=(m>c)?m:c; //反之执行冒号右侧
    printf("%d\n",m);
    return 0;
}
*/
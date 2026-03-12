//最大公约数
#include<stdio.h>
int main(void)
{
    int a, b, i;
    scanf("%d %d", &a, &b);
    if (a<b)
    {
        i = a; a = b; b = i;
    }
    for (i=b; i>=1; i--)
    {
        if (a%i==0&&b%i==0)
        {
            printf("%d", i);
            break;
        }
    }
    return 0;
}

//continue写法1
#include<stdio.h>
int main(void)
{
    int m, n, o, i;
    scanf("%d %d", &m, &n);
    if (m<n)
    {
        i = m; m = n; n = i;
    }
    for (i=1; i<=n; i++)
    {
        if (m%i!=0||n%i!=0)
            continue;
        o = i;
    }
    printf("%d", o);
    return 0;
}

// continue写法2
#include<stdio.h>
int main(){
    int m,n,i,t,gcd;
    scanf("%d%d",&m,&n);
    t=(m<n)?m:n;
    for(i=1;i<=t;i++){
        if(!(m%i==0 && n%i==0))
            continue;
        gcd=i;
    }
    printf("%d\n",gcd);
    return 0;
}
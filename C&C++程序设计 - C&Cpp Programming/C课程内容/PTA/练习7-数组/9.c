#include <stdio.h>
#include <math.h>
int a[110];
int main(void)
{
    int x;
    scanf("%d",&x);
    for(int i=1;i<=x;i++)
        scanf("%d",&a[i]);
    int max=-1,b=0;
    for(int i=1;i<=x;i++)
    {
        if(max<a[i])
        {
            max=a[i];
            b=i-1;
        }
    }
    printf("%d %d",max,b);
    return 0;
}





#include <stdio.h>
int main(void)
{
    int n,i,j;
    scanf("%d",&n);
    int a[11];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(j=0;j<n;j++)
    {
        if(a[0]<a[j])
        {
            a[0]=a[j];
            i=j;
        }
        else if(a[0]==a[j])
        {
            a[0]=a[j];
            if(i>j)
                i=j;
        }
    }
    printf("%d %d",a[0],i);
}
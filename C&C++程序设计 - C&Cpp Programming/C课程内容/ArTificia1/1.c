/*
#include<stdio.h>
int BinSeek(int a[], int n, int x)
{
    int low=0, high=n-1, mid, index=-1, flag=0;
    while(flag==0 && low<=high)
    {
        mid = (low + high) / 2;
        if (a[mid]==x)
        {
            index = mid;
            flag = 1;
        }
        if(a[mid]>x)
            high = mid - 1;
        if(a[mid]<x)
            low = mid + 1;
    }
    return index;
}
int main(void)
{
    int n, x, index;
    scanf("%d %d", &n, &x);
    int a[n]; int *p;
    for(p=a; p<a+n; p++)
        scanf("%d",p);
    index = BinSeek(a, n, x);
    if (index==-1)
        printf("Not Found!");
    else
        printf("%d", index);
    return 0;
}
*/
/*
#include<stdio.h>
#include<string.h>

#define N 1010
int main()
{
   char ch[N];
   getcher();
   int c=0,i;
   while (ch[i]!='@')
   {
       i++;
       if(ch[i]='\0')
       {
           c++;
       }
   }
   printf("%d",c);
    return 0;
}
*/

#include<stdio.h>
#define N 1010
int main(void)
{
    char ch[N]; char *pc=ch;
    int count=0;
    while (~scanf("%c", pc))
    {
        if (*pc=='@')
            break;
        if (*pc=='\n')
            count++;
        pc++;
    }
    printf("%d", count);
    return 0;
}
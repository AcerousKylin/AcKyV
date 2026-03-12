#include<iostream>
using namespace std;

int myin(int* p)
{
    int n=0;
    cin>>*p;
    while(*p!=-9999)
    {
        cin>>*(++p);
        n++;
    }
    return n;
}

void print(int* p, int n)
{
    int i;
    for (i=0; i<=n; i++)
    {
        cout<<p[i];
        if (i!=n)
            cout<<" ";
    }
    cout<<endl;
}

void print(double* p, int n)
{
    int i;
    for (i=0; i<=n; i++)
    {
        cout<<p[i];
        if (i!=n)
            cout<<" ";
    }
    cout<<endl;
}

int main(void)
{
    int n[100];
    int *p=n;
    int a=myin(p);
    int i;
    for (i=a-1; i>=0; i--)
    {
        cout<<n[i];
        if (i!=0)
            cout<<" ";
    }
    return 0;
}
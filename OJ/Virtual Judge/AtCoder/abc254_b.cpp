#include<iostream>
using namespace std;

int* Define(int *s, int n)
{
    int *a = {new int[n]};
    for(int i=0; i<n; i++)
    {
        if(i==0 || i==n-1)
            a[i] = 1;
        else
            a[i] = s[i-1] + s[i];
    }
    for (int i=0; i<n; i++)
    {
        cout<<a[i];
        if (i!=n-1)
            cout<<" ";
        else
            cout<<endl;
    }
    return a;
}

int main(void)
{
    int n;
    cin>>n;
    int a[1] = {1};
    int *p = a;
    for(int i=0; i<n; i++)
    {
        int *temp = Define(p, i+1);
        p = temp;
    }
    delete p;
    return 0;
}
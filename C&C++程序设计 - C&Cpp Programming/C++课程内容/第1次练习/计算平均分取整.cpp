#include<iostream>
using namespace std;

double Aver(int* p, int n);

int main(void)
{
    int i, a[7];
    for (i=0; i<7; i++)
        cin>>a[i];
    cout<<(int)(Aver(a, 7)+0.5)<<endl;
    return 0;
}

double Aver(int* p, int n)
{
    int i;
    double sum=0;
    for(i=0; i<n; i++)
        sum += p[i];
    return sum/n;
}
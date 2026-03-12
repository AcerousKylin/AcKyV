#include<iostream>
using namespace std;

double mypow(double x, int k);

int main(void)
{
    double x;
    int k;
    cin>>x>>k;
    cout<<mypow(x, k)<<endl;
    return 0;
}

double mypow(double x, int k)
{
    k==0? return 1 : return x*mypow(x, k-1);
}

//正负次幂都可用！
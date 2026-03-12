#include<bits/stdc++.h>
using namespace std;

const int N = 5;

long long tri[N];

long long gcd(long long m, long long n)
{
    if (n == 0)
        return m;
    return gcd(n, m % n);
}

int main(void)
{
    for (int i=0; i<3; i++)
        scanf("%lld", &tri[i]);
    
    sort(tri, tri+3);

    int g = gcd(tri[0], tri[2]);

    printf("%lld/%lld", tri[0]/g, tri[2]/g);

    return 0;
}
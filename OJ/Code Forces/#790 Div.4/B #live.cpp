#include<iostream>
using namespace std;

int solution(void)
{
    int n;
    cin>>n;
    int candy[n];
    for (int i=0; i<n; i++)
    {
        cin>>candy[i];
    }
    int avrg = candy[0];
    for(int i=1; i<n; i++)
    {
        if (avrg>candy[i])
            avrg = candy[i];
    }
    int eaten = 0;
    for (int i=0; i<n; i++)
    {
        eaten += candy[i] - avrg;
    }
    return eaten;
}

int main(void)
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
        cout<<solution()<<endl;
    return 0;
}
#include<iostream>
using namespace std;

int main(void)
{
    int i;
    cin>>i;
    cout<<i;
    cout<<" ";
    i<0?cout<<"-"<<hex<<-i:cout<<hex<<i;
    cout<<" ";
    i<0?cout<<"-"<<oct<<-i:cout<<oct<<i;
    return 0;
}
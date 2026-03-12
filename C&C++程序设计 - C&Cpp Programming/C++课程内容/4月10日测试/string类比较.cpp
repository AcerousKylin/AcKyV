#include<iostream>
#include<string>
using namespace std;

int main(void)
{
    cout<<"请输入两句话："<<endl;
    string s1, s2;
    cin>>s1>>s2;
    cout<<"两句话连接的结果："<<s1<<s2<<endl;
    if (s1>s2)
        cout<<s1<<"大于"<<s2<<endl;
    if (s1<s2)
        cout<<s1<<"小于"<<s2<<endl;
    if (s1==s2)
        cout<<s1<<"等于"<<s2<<endl;
    return 0;
}
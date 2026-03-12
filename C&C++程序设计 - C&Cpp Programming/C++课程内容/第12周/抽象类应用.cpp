#include<iostream>
#include<cmath>
using namespace std;

class Base
{
    public:
        int a;
        int n;
        Base(int a0, int n0):a(a0), n(n0) {}
        virtual void disp()=0;
};

class pa1:public Base
{
    public:
        pa1(int a0):Base(a0, 0) {}
        void disp()
        {
            cout<<pow(a, 2)<<endl;
        }
};

class pa2:public Base
{
    public:
        pa2(int a0):Base(a0, 0) {}
        void disp()
        {
            cout<<pow(a, 3)<<endl;
        }
};

class pa3:public Base
{
    public:
        pa3(int a0, int n0):Base(a0, n0) {}
        void disp()
        {
            cout<<pow(a, n)<<endl;
        }
};

int main(void)
{
    cout<<"输入a和n的值"<<endl;
    int n, a;
    cin>>a>>n;
    pa1 p1(a);
    pa2 p2(a);
    pa3 p3(a, n);
    p1.disp();
    p2.disp();
    p3.disp();
    return 0;
}
#include<iostream>
#include<string>
using namespace std;

class A
{
    public:
        virtual void func1()
        { cout << "A1" << endl; }
        void func2()
        { cout << "A2" << endl; }
};

class B: public A
{
    public:
        void func1()
        { cout << "B1" << endl; }
        void func2()
        { cout << "B2" << endl; }
};

int main(void)
{
    A *P = new B;
    p->func1();
    p->func2();
    delete;
    return 0;
}
#include<iostream>
using namespace std;

class A
{
    public:
        static int a;
        void init()
        {
            a = 1; // init中的a是真正的成员a，可以做出更改
            cout<<"member init() occurred!"<<endl;
            cout<<"a="<<a<<endl;
        }
        A(int a = 2) // 构造函数中的a均为形参a，与成员a不同
        {
            init();
            a++;
            cout<<"constructor A occurred!"<<endl;
            cout<<"a="<<a<<endl;
        }
};

int A::a = 0; // 初始化，等同于在成员定义处赋值
A obj;

int main(void)
{
    cout << obj.a;
    return 0;
}
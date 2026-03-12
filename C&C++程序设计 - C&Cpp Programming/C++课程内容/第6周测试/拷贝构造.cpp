#include<iostream>
using namespace std;

class Class
{
    private:
        int i;
    public:
        Class(int a);
        Class(const Class &p);
        void show();
};

Class::Class(int a)
{
    i = a;
}

Class::Class(const Class &p)
{
    i = 2 * p.i;
}

void Class::show()
{
    cout<<i;
}

int main(void)
{
    int a;
    cin>>a;
    Class c1(a);
    Class c2(c1);
    c2.show;
    return 0;
}
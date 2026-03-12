#include<iostream>
using namespace std;

class Class
{
    private:
        int member;
    public:
        Class(int m):member(m) {}
        Class(Class &);
        int getMember();
        void showMember();
};

Class::Class(Class &c)
{
    member = c.getMember();
}

int Class::getMember()
{
    return 2*member;
}

void Class::showMember()
{
    cout<<member;
}

int main(void)
{
    int m;
    cin>>m;
    Class c1(m), c2(c1);
    c2.showMember();
    return 0;
}
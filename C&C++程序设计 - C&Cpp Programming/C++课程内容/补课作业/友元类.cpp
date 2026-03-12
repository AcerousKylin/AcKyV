#include<iostream>
#include<string>
using namespace std;

class girl;

class boy
{
    private:
        string name;
        int age;
    public:
        boy(string n, int a):name(n),age(a) {}
        void disp(girl &);
};

class girl
{
    private:
        string name;
        int age;
    public:
        girl(string n, int a):name(n),age(a) {}
        friend boy;
};

void boy::disp(girl &g)
{
    cout<<"女孩的姓名是："<<g.name<<endl;
    cout<<"男孩的姓名是："<<name<<endl;
    cout<<"女孩的年龄是："<<g.age<<endl;
    cout<<"男孩的年龄是："<<age<<endl;
}

int main(void)
{
    string n;
    int a;
    cin>>n>>a;
    girl g(n, a);
    cin>>n>>a;
    boy b(n, a);
    b.disp(g);
    return 0;
}
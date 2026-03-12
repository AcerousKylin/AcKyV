#include<iostream>
#include<string>
using namespace std;

class girl
{
    private:
        string name;
        int age;
    public:
        girl(string n, int a)
        {
            name = n;
            age = a;
        }
        friend void disp(girl &g);
};

void disp(girl &g)
{
    cout<<"女孩的姓名是："<<g.name<<",年龄是："<<g.age<<endl;
}

int main(void)
{
    string n;
    int a;
    cin>>n>>a;
    girl g(n, a);
    disp(g);
    return 0;
}
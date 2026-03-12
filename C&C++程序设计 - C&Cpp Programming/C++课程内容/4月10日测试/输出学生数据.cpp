#include<iostream>
#include<string>
using namespace std;

class student
{
    private:
        string number;
        float grade;
    public:
        student(string n, float g);
        student():number("M0000000"), grade(-1) {}
        void display();
};

student::student(string n, float g)
{
    number = n;
    grade = g;
}

void student::display()
{
    cout<<number<<":"<<grade<<endl;
}

int main(void)
{
    cout<<"请分别输出5个学生的学号和成绩："<<endl;
    student s[5];
    int i;
    for (i=0; i<5; i++)
    {
        string n;
        float g;
        cin>>n>>g;
        s[i] = student(n, g);
    }
    s[0].display();
    s[2].display();
    s[4].display();
    return 0;
}
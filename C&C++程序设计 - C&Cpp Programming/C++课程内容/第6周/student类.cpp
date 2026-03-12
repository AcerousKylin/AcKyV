#include<iostream>
#include<string>
using namespace std;

class student
{
    private:
        string number;
        float grade;
    public:
        student();
        student(string n, float g);
        void display();
};

student::student()
{
    number = "M0000000";
    grade = -1;
}

student::student(string n, float g)
{
    number = n;
    grade  = g;
}

void student::display()
{
    cout<<number<<":"<<grade<<endl;
}

int main(void)
{
    student p[5];
    int i;
    for (i=0; i<5; i++)
    {
        string n;
        float g;
        cin>>n>>g;
        p[i] = {student(n ,g)};
    }
    cout<<"请分别输出5个学生的学号和成绩："<<endl;
    for (i=0; i<5; i+=2)
    {
        p[i].display();
    }
    return 0;
}
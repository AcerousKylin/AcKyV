#include<iostream>
#include<string>
using namespace std;

class Date_rec
{
    public:
        string name;
        char sex;
        int age;
        Date_rec(string n, char s, int a):name(n), sex(s), age(a) {}
};

class Student:virtual public Date_rec
{
    public:
        string major;
        double score;
        Student(string n, char s, int a, string m, double sk):Date_rec(n, s, a), major(m), score(sk) {}
};

class Employee:virtual public Date_rec
{
    public:
        string dept;
        double salary;
        Employee(string n, char s, int a, string d, double slr):Date_rec(n, s, a), dept(d), salary(slr) {}
};

class E_Student:public Employee, public Student
{
    public:
        E_Student(string n, char s, int a, string m, double sk, string d, double slr):Date_rec(n, s, a), Employee(n, s, a, d, slr), Student(n, s, a, m, sk) {}
        void print();
};

void E_Student::print()
{
    cout<<"姓名："<<name<<endl;
    cout<<"性别："<<sex<<endl;
    cout<<"年龄："<<age<<endl;
    cout<<"成绩："<<score<<endl;
    cout<<"专业："<<major<<endl;
    cout<<"部门："<<dept<<endl;
    cout<<"酬金："<<salary<<endl;
}

int main(void)
{
    int age;
    double score, salary;
    char sex;
    string name, major, department;
    cout<<"依次输入在职大学生的姓名、性别、年龄、专业、成绩、部门、酬金"<<endl;
    cin>>name>>sex>>age>>major>>score>>department>>salary;
    E_Student e(name, sex, age, major, score, department, salary);
    e.print();
    return 0;
}

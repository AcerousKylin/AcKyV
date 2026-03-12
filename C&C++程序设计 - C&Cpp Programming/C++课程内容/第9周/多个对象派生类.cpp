#include<iostream>
#include<string>
using namespace std;

class Student
{
    private:
        string number;
        string name;
        int score;
    public:
        Student(string num, string nam, int s):number(num), name(nam), score(s) {}
        void print()
        {
            cout<<"学号："<<number<<endl;
            cout<<"姓名："<<name<<endl;
            cout<<"成绩："<<score<<endl;
        }
};

class Ustudent:public Student
{
    private:
        string major;
        Student auditor1;
        Student auditor2;
    public:
        Ustudent(string num0, string nam0, int s0, string m, string num1, string nam1, int s1, string num2, string nam2, int s2):Student(num0, nam0, s0), major(m), auditor1(num1, nam1, s1), auditor2(num2, nam2, s2)
        {}
        void print()
        {
            cout<<"正式生是："<<endl;
            Student::print();
            cout<<"专业："<<major<<endl;
        }
        void print_auditor1()
        {
            cout<<"旁听生是："<<endl;
            auditor1.print();
        }
        void print_auditor2()
        {
            cout<<"旁听生是："<<endl;
            auditor2.print();
        }
};

int main(void)
{
    string num0, nam0, num1, nam1, num2, nam2, major;
    int score0, score1, score2;
    cin>>num0>>nam0>>score0;
    cin>>num1>>nam1>>score1;
    cin>>num2>>nam2>>score2;
    cin>>major;
    Ustudent u(num0, nam0, score0, major, num1, nam1, score1, num2, nam2, score2);
    u.print();
    u.print_auditor1();
    u.print_auditor2();
    return 0;
}
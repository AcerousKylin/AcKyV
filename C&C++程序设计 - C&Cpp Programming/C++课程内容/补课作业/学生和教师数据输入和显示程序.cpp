#include<iostream>
#include<string>
using namespace std;

class Person
{
    private:
        string name;
        string code;
    public:
        Person(string c, string n):code(c), name(n) {}
        void print()
        {
            cout<<"编号："<<code<<endl;
            cout<<"姓名："<<name<<endl;
        }
};

class Student:public Person
{
    private:
        string classcode;
        int mark;
    public:
        Student(string c, string n, string cc, int m):Person(c, n), classcode(cc), mark(m) {}
        void print()
        {
            cout<<"显示一个学生数据："<<endl;
            Person::print();
            cout<<"班号："<<classcode<<endl;
            cout<<"成绩："<<mark<<endl;
        }
};

class Teacher:public Person
{
    private:
        string headship;
        string settlement;
    public:
        Teacher(string c, string n, string h, string s):Person(c, n), headship(h), settlement(s) {}
        void print()
        {
            cout<<"显示一个教师数据："<<endl;
            Person::print();
            cout<<"职称："<<headship<<endl;
            cout<<"部门："<<settlement<<endl;
        }
};

int main(void)
{
    int mark;
    string code, name, classcode, headship, settlement;
    
    cout<<"输入一个学生数据："<<endl;
    cin>>code>>name>>classcode>>mark;
    Student student(code, name, classcode, mark);
    
    cout<<"输入一个教师数据："<<endl;
    cin>>code>>name>>headship>>settlement;
    Teacher teacher(code, name, headship, settlement);
    
    student.print();
    teacher.print();
    return 0;
}
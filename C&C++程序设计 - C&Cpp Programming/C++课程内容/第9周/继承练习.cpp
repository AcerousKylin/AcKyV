#include<iostream>
#include<string>
using namespace std;

class Person
{
    protected:
        string name;
        char sex;
    public:
        Person(string n, char s):name(n), sex(s) {}
        void print()
        {
            cout<<"Name:"<<name<<", Sex:"<<sex<<endl;
        }
};

class Student:public Person
{
    private:
        string status;
    public:
        Student(string n, char se, string st):Person(n, se), status(st) {}
        void print()
        {
            Person::print();
            cout<<status<<endl;
        }
};

class MyDate
{
    private:
        int year;
        int month;
        int day;
    public:
        MyDate(int y, int m, int d):year(1900), month(1), day(1)
        {
            year = y;
            month = m;
            day = d;
        }
        void print()
        {
            cout<<"Hire date:"<<year<<"-"<<month<<"-"<<day<<endl;
        }
};

class Employee:public Person
{
    protected:
        int salary;
        MyDate dateHired;
    public:
        Employee(string n, char se, int sa, MyDate d):Person(n, se), salary(sa), dateHired(d) {}
        void print()
        {
            Person::print();
            cout<<"Salary:"<<salary<<", ";
            dateHired.print();
        }
};

class Faculty:public Employee
{
    private:
        string rank;
    public:
        Faculty(string n, char se, int sa, MyDate d, string r):Employee(n, se, sa, d), rank(r) {}
        void print()
        {
            Employee::print();
            cout<<rank<<endl;
        }
};

class Stuff:public Employee
{
    private:
        string headship;
    public:
        Stuff(string n, char se, int sa, MyDate d, string h):Employee(n, se, sa, d), headship(h) {}
        void print()
        {
            Employee::print();
            cout<<headship<<endl;
        }
};

int main(void)
{
    string name, status, rank, headship;
    char sex;
    int year, month, day, salary;
    
    cin>>name>>sex;
    Person person(name, sex);
    person.print();
    
    cin>>name>>sex>>status;
    Student student(name, sex, status);
    student.print();
    
    cin>>year>>month>>day;
    MyDate date(year, month, day);

    cin>>name>>sex>>salary;
    Employee employee(name, sex, salary, date);
    employee.print();

    cin>>name>>sex>>salary>>rank;
    Faculty faculty(name, sex, salary, date, rank);
    faculty.print();

    cin>>name>>sex>>salary>>headship;
    Stuff stuff(name, sex, salary, date, headship);
    stuff.print();

    return 0;
}
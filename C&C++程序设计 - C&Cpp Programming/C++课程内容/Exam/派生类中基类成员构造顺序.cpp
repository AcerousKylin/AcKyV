#include<bits/stdc++.h>
#include<string.h>
using namespace std;

class Person
{
    public:
        Person(string n):name(n) { cout << 'P'; }
    private:
        string name;
};

class Date
{
    public:
        Date(int y=2012, int m=12, int d=23):year(y), month(m), day(d) { cout<< 'D'; }
    private:
        int year, month, day;
};

class Student:public Person
{
    public:
        Student(string n, int y, int m, int d, int c):
            birthday(y, m ,d), sex(c), Person(n)
        { cout << 'S'; }
    private:
        Date birthday;
        char sex;
};

int main(void)
{
    Student stu1("Zhang", 1990, 10, 1, 'f');
    return 0;
}
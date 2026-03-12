#include<iostream>
#include<string>
using namespace std;

class student
{
    private:
        string number;
        float grade;
    public:
        student(string num, float g);
        float getgrade();
        string getnum();
};

student::student(string num = "blank", float g = 0)
{
    number = num;
    grade = g;
}

float student::getgrade()
{
    return grade;
}

string student::getnum()
{
    return number;
}

void max(student* a)
{
    int i, symbol;
    float max = -1;
    for (i=0; i<5; i++)
    {
        if ( a[i].getgrade() > max )
        {
            symbol = i;
            max = a[i].getgrade();
        }
    }
    cout<<"请分别输出5个学生的学号和成绩："<<endl;
    cout<<a[symbol].getgrade()<<" "<<a[symbol].getnum();
}

int main(void)
{
    student stu[10];
    int i;
    for (i=0; i<5; i++)
    {
        string num;
        float g;
        cin>>num>>g;
        stu[i] = {student(num, g)};
    }
    max(stu);
    return 0;
}
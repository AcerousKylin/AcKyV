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

int main(void)
{
    student stu[100];
    int i, j, k;
    for (i=0; i<100; i++)
    {
        string num;
        float g;
        cin>>num>>g;
        if (num=="0")
            break;
        stu[i] = {student(num, g)};
    }
    k = i;
    for (i=0; i<k; i++)
    {
        for (j=i+1; j<k; j++)
        {
            if (stu[i].getgrade()<stu[j].getgrade())
            {
                student temp;
                temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }
        }
    }
    for (i=0; i<k; i++)
        cout<<stu[i].getnum()<<" "<<stu[i].getgrade()<<endl;
    return 0;
}
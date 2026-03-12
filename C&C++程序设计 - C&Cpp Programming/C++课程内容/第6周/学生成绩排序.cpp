#include<iostream>
#include<string>
using namespace std;

class Student
{
    private:
        double math;
        double chinese;
        string name;
    public:
        void init(double m, double c, string n);
        double total;
        double add();
        void output();
};

void Student::init(double m, double c, string n)
{
    math = m;
    chinese = c;
    name = n;
}

void Student::output()
{
    cout<<"姓名="<<name<<" 数学="<<math<<" 语文="<<chinese<<" 总分="<<total;
    cout<<endl;
}

double Student::add()
{
    total = math + chinese;
}

int main(void)
{
    cout<<"请输入学生人数（小于20）,每个的姓名，数学成绩，语文成绩："<<endl;
    int n;
    cin>>n;
    Student s[20];
    int i, j;
    for (i=0; i<n; i++)
    {
        double m, c;
        string n;
        cin>>n>>m>>c;
        s[i].init(m, c, n);
        s[i].add();
    }
    cout<<"排序结果如下:"<<endl;
    for (i=0; i<n; i++)
    {
        for (j=i+1; j<n; j++)
        {
            if (s[i].total<s[j].total)
            {
                Student temp;
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    for (i=0; i<n; i++)
        s[i].output();
    return 0;
}
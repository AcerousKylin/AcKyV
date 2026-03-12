#include<iostream>
#include<string>
using namespace std;

class Employee
{
    public:
        string name;
        double score;
        Employee(string name, double score):name(name), score(score) {}
        void display()
        {
            cout<<name<<"本月工资"<<score<<endl;
        }
};

class Technician:public Employee
{
    public:
        double salary_per_hour;
        double working_time;
        Technician(string name, double w_t):
            Employee(name, 0),
            working_time(w_t), salary_per_hour(100)
        {}
        void display()
        {
            score = working_time*salary_per_hour;
            Employee::display();
        }
};

class Salesman:virtual public Employee
{
    public:
        double percentage;
        double saleroom;
        Salesman(string name, double saleroom):
            Employee(name, 0),
            percentage(0.04), saleroom(saleroom)
        {}
        void display()
        {
            score = percentage*saleroom;
            Employee::display();
        }
};

class Manager:virtual public Employee
{
    public:
        double m_stable_salary;
        Manager(string name):
            Employee(name, 0),
            m_stable_salary(8000)
        {}
        void display()
        {
            score = m_stable_salary;
            Employee::display();
        }
};

class Salesmanager:public Salesman, public Manager
{
    public:
        double sm_stable_salary;
        double presidial_percentage;
        double presidial_saleroom;
        Salesmanager(string name, double s, double p_s):
            Employee(name, 0), Salesman(name, s), Manager(name),
            sm_stable_salary(5000), presidial_saleroom(p_s), presidial_percentage(0.005)
        {}
        void display()
        {
            score = sm_stable_salary+presidial_percentage*presidial_saleroom;
            Employee::display();
        }
};

int main(void)
{
    cout<<"分别输入经理、技术人员、销售经理、销售员的姓名"<<endl;
    string name1, name2, name3, name4;
    cin>>name1>>name2>>name3>>name4;

    double working_time, saleroom, presidial_saleroom;
    cout<<"请输入加班工时、当月销售额、所管部门当月销售额"<<endl;
    cin>>working_time>>saleroom>>presidial_saleroom;

    Technician t(name2,working_time);
    Salesman sman(name4, saleroom);
    Manager m(name1);
    Salesmanager smng(name3, saleroom, presidial_saleroom);

    m.display();
    t.display();
    smng.display();
    sman.display();

    return 0;
}
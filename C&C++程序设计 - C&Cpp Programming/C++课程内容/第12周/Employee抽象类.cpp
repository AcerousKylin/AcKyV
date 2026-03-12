#include<iostream>
#include<string>
using namespace std;

class Employee
{
    private:
        string name;
    public:
        Employee(string n):name(n) {}
        string getName()
        {   return name;    }
        virtual void show()=0;
        virtual void earnings()=0;
};

class Boss:public Employee
{
    private:
        double weeklySalary;
    public:
        Boss(string n, double ws):Employee(n), weeklySalary(ws) {}
        void setWeeklySalary(double ws)
        {   weeklySalary = ws;  }
        void show()
        {   cout<<"Boss: "<<getName()<<endl;  }
        void earnings()
        {   cout<<"Earned: $"<<weeklySalary<<endl;  }
};

class CommissionWorkers:public Employee
{
    private:
        double salary;
        double commission;
        int quantity;
    public:
        CommissionWorkers(string n, double s, double c, int q):Employee(n), salary(s), commission(c), quantity(q) {}
        void setSalary(double s)
        {   salary = s; }
        void setCommission(double c)
        {   commission = c; }
        void setQuantity(int q)
        {   quantity = q;   }
        void show()
        {   cout<<"Commission Worker: "<<getName()<<endl;   }
        void earnings()
        {   cout<<"Earned: $"<<salary+quantity*commission<<endl;    }
};

class PieceWorker:public Employee
{
    private:
        double wagePerPiece;
        int quantity;
    public:
        PieceWorker(string n, double wpp, int q):Employee(n), wagePerPiece(wpp), quantity(q) {}
        void setWage(double wpp)
        {   wagePerPiece = wpp; }
        void setQuantity(int q)
        {   quantity = q;   }
        void show()
        {   cout<<"Piece Worker: "<<getName()<<endl;    }
        void earnings()
        {   cout<<"Earned: $"<<wagePerPiece*quantity<<endl; }
};

class HourlyWorker:public Employee
{
    private:
        double wage;
        double hours;
    public:
        HourlyWorker(string n, double w, double h):Employee(n), wage(w), hours(h) {}
        void setWage(double w)
        {   wage = w;   }
        void setHour(double h)
        {   hours = h;  }
        void show()
        {   cout<<"Hourly Worker: "<<getName()<<endl;   }
        void earnings()
        {   cout<<"Earned: $"<<wage*hours<<endl;    }
};

int main(void)
{
    string name;
    {
        double weeklySalary;
        cin>>name>>weeklySalary;
        Boss b(name, weeklySalary);
        b.show(); b.earnings();
    }

    {
        double salary, commission;
        int quantity;
        cin>>name>>salary>>commission>>quantity;
        CommissionWorkers cw(name, salary, commission, quantity);
        cw.show(); cw.earnings();
    }

    {
        double wagePerPiece;
        int quantity;
        cin>>name>>wagePerPiece>>quantity;
        PieceWorker pw(name, wagePerPiece, quantity);
        pw.show(); pw.earnings();
    }

    {
        double wage, hours;
        cin>>name>>wage>>hours;
        HourlyWorker hw(name, wage, hours);
        hw.show(); hw.earnings();
    }

    return 0;
}
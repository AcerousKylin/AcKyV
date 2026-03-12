#include<iostream>
using namespace std;

class Date
{
    private:
        int year;
        int month;
        int day;
    public:
        void setDate(int y, int m ,int d);
        void showDate();
};

void Date::setDate(int y, int m ,int d)
{
    year = y;
    month = m;
    day = d;
}

void Date::showDate()
{
    cout<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
}

int main(void)
{
    Date S;
    int y, m, d;
    cin>>y>>m>>d;
    S.setDate(y, m, d);
    S.showDate();
    return 0;
}
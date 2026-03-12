//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Time
{
    private:
        int hour;
        int minute;
        int second;
    public:
        Time(int h, int m, int s):hour(h), minute(m), second(s) {}
        Time operator++();
        Time operator--();
        void display();
};

Time Time::operator++()
{
    hour++;
    if (hour>=24)
        hour -= 24;
    return *this;
}

Time Time::operator--()
{
    hour--;
    if (hour<0)
        hour += 24;
    return *this;
}

void Time::display()
{
    cout<<hour<<":"<<minute<<":"<<second<<endl;
}

int main(void)
{
    int h, m ,s;
    cin>>h>>m>>s;
    Time t(h, m, s);

    cout<<"time:";
    t.display();

    cout<<"++time:";
    Time tpp(t);
    (++tpp).display();

    cout<<"--time:";
    Time tmm(t);
    (--tmm).display();

    return 0;
}

//49行和53行可在运算符重载时创建临时对象代替，且更提倡后者
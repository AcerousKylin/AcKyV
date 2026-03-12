#include<iostream>
using namespace std;

class Timer
{
    private:
        int second;
        int minute;
    public:
        Timer();
        Timer(int s);
        Timer(int m, int s);
        void disp();
};

Timer::Timer():second(0),minute(0)
{
    second = 0;
    minute = 0;
    cout<<"0 parameter"<<endl;
}

Timer::Timer(int s):second(0)
{
    second = s;
    minute = 0;
    cout<<"1 int parameter"<<endl;
}

Timer::Timer(int m, int s)
{
    second = s;
    minute = m;
    cout<<"2 parameters"<<endl;
}

void Timer::disp()
{
    cout<<second+60*minute<<endl;
}

int main(void)
{
    int s1;
    cin>>s1;
    int s2, m;
    cin>>m>>s2;
    Timer t1;
    Timer t2(s1);
    Timer t3(m, s2);
    cout<<"seconds1="; t1.disp();
    cout<<"seconds2="; t2.disp();
    cout<<"seconds3="; t3.disp();
    return 0;
}
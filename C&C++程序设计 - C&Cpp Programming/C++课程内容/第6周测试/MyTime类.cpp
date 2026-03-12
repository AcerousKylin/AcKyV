#include<iostream>
using namespace std;

class MyTime
{
    private:
        int hour;
        int minute;
        int second;
    public:
        void SetTime(int h, int m, int s);
        void print_12();
        void print_24();
};

void MyTime::SetTime(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

void MyTime::print_12()
{
    if (hour>12)
    {
        if (hour-12<10)
            cout<<"0";
        cout<<hour-12<<":"<<minute<<":"<<second<<" PM"<<endl;
    }
    else
        cout<<hour<<":"<<minute<<":"<<second<<" AM"<<endl;
}

void MyTime::print_24()
{
    cout<<hour<<":"<<minute<<":"<<second<<endl;
}

int main(void)
{
	int h, m, s;
	cin >> h >> m >> s;
	MyTime clock;
	clock.SetTime(h, m, s);
	clock.print_12();
	clock.print_24();
	return 0;
}
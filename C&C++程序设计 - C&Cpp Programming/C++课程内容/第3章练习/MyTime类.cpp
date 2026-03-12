#include<iostream>
#include<cstdio>
using namespace std;

class MyTime
{
    private:
        int hour;
        int minute;
        int second;
    public:
        void SetTime(int, int ,int);
        void print_12();
        void print_24();
};

void MyTime::SetTime(int h, int m, int s)
{
    hour = h;   minute = m; second = s;
}

void MyTime::print_12()
{
    int temp = hour;
    temp %= 12; //hour=12 -?> hour=0 ;
    printf("%02d:%2d:%2d", temp, minute, second);
    if (hour>=12)    printf(" PM\n");
    else            printf(" AM\n");
}

void MyTime::print_24()
{
    printf("%02d:%2d:%2d\n", hour, minute, second);
    //cout<<hour<<":"<<minute<<":"<<second<<endl;
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
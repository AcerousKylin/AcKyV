#include<iostream>
using namespace std;

inline void display(int number)
{
    number %= 7;
    switch(number)
    {
        case 0: cout<<"星期日"<<endl;   break;
        case 1: cout<<"星期一"<<endl;   break;
        case 2: cout<<"星期二"<<endl;   break;
        case 3: cout<<"星期三"<<endl;   break;
        case 4: cout<<"星期四"<<endl;   break;
        case 5: cout<<"星期五"<<endl;   break;
        case 6: cout<<"星期六"<<endl;   break;
        default:    cout<<"Invalid Input"<<endl;
    }
}

class Weekday
{
    private:
        int weekday;
    public:
        void SetDay();
        void NowDay();
        void IncDay();
};

void Weekday::SetDay()
{
    cin>>weekday;
}

void Weekday::NowDay()
{
    display(weekday);
}

void Weekday::IncDay()
{
        display(++weekday);
}

int main(void)
{
	Weekday day;
	day.SetDay();
	day.NowDay();
	for (int i = 0; i < 2; i++)
		day.IncDay();
	return 0;
}
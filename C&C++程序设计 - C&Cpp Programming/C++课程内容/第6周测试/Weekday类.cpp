#include<iostream>
using namespace std;

class Weekday
{
    private:
        int date;
    public:
        void SetDay();
        void IncDay();
        void NowDay();
};

void Weekday::SetDay()
{
    cin>>date;
}

void Weekday::IncDay()
{
    date += 1;
    date %= 7;
}

void Weekday::NowDay()
{
    switch(date)
    {
        case 1:
            cout<<"星期一"<<endl;
            break;
        case 2:
            cout<<"星期二"<<endl;
            break;
        case 3:
            cout<<"星期三"<<endl;
            break;
        case 4:
            cout<<"星期四"<<endl;
            break;
        case 5:
            cout<<"星期五"<<endl;
            break;
        case 6:
            cout<<"星期六"<<endl;
            break;
        case 0:
            cout<<"星期日"<<endl;
            break;
        default:
            cout<<"Invalid Date"<<endl;
    }
}

int main(void)
{
	Weekday day;
	day.SetDay();
	for (int i=0; i<3; i++)
	{
		day.NowDay();
		day.IncDay();
	}
	return 0;
}
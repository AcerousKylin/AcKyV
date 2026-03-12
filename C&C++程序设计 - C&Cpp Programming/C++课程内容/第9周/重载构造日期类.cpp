#include<iostream>
using namespace std;

class Date
{
    private:
        int year;
        int month;
        int day;
    public:
        Date():year(1900), month(1), day(1) {}
        Date(int y, int m, int d):year(y), month(m), day(d) {}
        void init(int y, int m, int d)
        {
            year = y;
            month = m;
            day = d;
        }
        void show()
        {
            cout<<year<<"-"<<month<<"-"<<day<<endl;
        }
};

int main(void)
{
	int y, m, d;
	cin >> y >> m >> d;
	Date d1, d2(2100, 12, 12);
	d1.show();
	d2.show();
	d1.init(y, m, d);
	d1.show();
	return 0;
}
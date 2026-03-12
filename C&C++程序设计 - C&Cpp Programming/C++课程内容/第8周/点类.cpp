#include<iostream>
#include<cmath>
using namespace std;

class POINT
{
    private:
        double x;
        double y;
    public:
        void set(double x1, double x2);
        double distance(POINT &p);
        void show();
};

void POINT::set(double x1, double y1)
{
    x = x1;
    y = y1;
}

double POINT::distance(POINT &p)
{
    double dx, dy;
    dx = x - p.x;
    dy = y - p.y;
    return sqrt(dx * dx + dy * dy);
}

void POINT::show()
{
    cout<<"("<<x<<","<<y<<")"<<endl;
}

int main(void)
{
	POINT a, b;
	double x, y;
	cin >> x >> y;
	a.set(x, y);
	cin >> x >> y;
	b.set(x, y);
	a.show();
	b.show();
	cout << a.distance(b) << endl;
	return 0;
}
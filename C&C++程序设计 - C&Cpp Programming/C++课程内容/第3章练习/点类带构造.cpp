#include<iostream>
#include<cmath>
using namespace std;

class POINT
{
    private:
        double x;
        double y;
    public:
        void set(double x0, double y0);
        double distance(POINT p);
        void show();
        POINT(double x0=0.0, double y0=0.0);
};

POINT::POINT(double x0, double y0)
{
    x = x0;
    y = y0;
}

void POINT::set(double x0,double y0)
{
    x = x0;
    y = y0;
}

double POINT::distance(POINT p)
{
    POINT q;
    q.x = x - p.x;
    q.y = y - p.y;
    return sqrt(pow(q.x,2)+pow(q.y,2));
}

void POINT::show()
{
    cout << "(" <<  x << "," << y << ")";
}

int main(void)
{
	double x, y;
	cin >> x >> y;
	POINT a(x, y);
	cin >> x >> y;
	POINT b(x, y);
	a.show();
	cout << endl;
	b.show();
	cout << endl;
	cout << a.distance(b) << endl;
	return 0;
}
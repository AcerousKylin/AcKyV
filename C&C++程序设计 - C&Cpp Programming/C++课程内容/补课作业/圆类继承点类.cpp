#include<iostream>
using namespace std;

class POINT
{
    private:
        double x;
        double y;
    public:
        POINT():x(0), y(0) {}
        POINT(double x0, double y0):x(x0), y(y0) {}
        void set(double x0, double y0)
        {
            x = x0;
            y = y0;
        }
        void show()
        {
            cout<<"x="<<x<<" y="<<y;
        }
};

class Circle:public POINT
{
    private:
        double radius;
    public:
        Circle():POINT(), radius(0) {}
        Circle(double x0, double y0, double r):POINT(x0, y0), radius(r) {}
        void set(double x0, double y0, double r)
        {
            POINT::set(x0, y0);
            radius = r;
        }
        void show()
        {
            POINT::show();
            cout<<" r="<<radius<<endl;
        }
};

int main(void)
{
	Circle a;
	Circle b(1.0, 2.0, 3.0);
	a.show();
	b.show();
	double x, y, r;
	cin >> x >> y >> r;
	a.set(x, y, r);
	a.show();
	return 0;
}
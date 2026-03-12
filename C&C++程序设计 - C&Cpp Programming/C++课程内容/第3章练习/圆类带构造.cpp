#include<iostream>
using namespace std;
const double Pi=3.1415926;

class CIRCLE
{
    private:
        double heart_x;
        double heart_y;
        double radius;
    public:
        void set(double x, double y, double r);
        double perimeter();
        double area();
        void show();
        CIRCLE(double r=0, double x=0, double y=0);
};

CIRCLE:: CIRCLE(double x, double y, double r)
{
    radius = r; heart_x = x; heart_y = y;
}

void CIRCLE::set(double x, double y, double r)
{
    radius = r;
    heart_x = x;
    heart_y = y;
}

double CIRCLE::perimeter()
{
    return 2*Pi*radius;
}

double CIRCLE::area()
{
    return Pi*radius*radius;
}

void CIRCLE::show()
{
    cout << "(" << heart_x << "," << heart_y << "," << radius << ")";
}

int main() {
	CIRCLE a;
	double x, y, r;
	cin >> x >> y >> r;
	CIRCLE b(x, y, r);
	a.show();
	cout << endl;
	cout << a.perimeter() << endl;
	cout << a.area() << endl;
	b.show();
	cout << endl;
	cout << b.perimeter() << endl;
	cout << b.area() << endl;
	return 0;
}
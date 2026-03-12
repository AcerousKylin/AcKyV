#include<iostream>
using namespace std;
const double Pi=3.1415926;

class CIRCLE
{
    private:
        double radius;
        double heart_x;
        double heart_y;
    public:
        void set(double x, double y, double r);
        double perimeter();
        double area();
        void show();
};

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
    cout << "(" << heart_x << "," << heart_y << "," << radius << ")" << endl;
}

int main(void)
{
	CIRCLE a;
	double x, y, r;
	cin >> x >> y >> r;
	a.set(x, y, r);
	a.show();
	cout << a.perimeter() << endl;
	cout << a.area() << endl;
	return 0;
}
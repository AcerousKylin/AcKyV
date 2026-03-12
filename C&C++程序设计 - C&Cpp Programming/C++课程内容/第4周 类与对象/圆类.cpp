/*
#include<iostream>
using namespace std;
const double Pi=3.14159;

class Circle
{
    private:
        int radius;
    public:
        void setRadius(int r);
        double getGirth();
        double getArea();
        void disp();
};

void Circle::setRadius(int r)
{
    radius = r;
}

double Circle::getGirth()
{
    return 2*Pi*radius;
}

double Circle::getArea()
{
    return Pi*radius*radius;
}

void Circle::disp()
{
    cout<< "周长为：" << getGirth() <<endl;
    cout<< "面积为：" << getArea() <<endl;
}

int main(void)
{
    int r;
    cin>>r;
    Circle c;
    c.setRadius(r);
    c.disp();
    return 0;
}
*/

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
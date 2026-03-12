#include<iostream>
using namespace std;

class Shape
{
    private:
        double x;
        double y;
    public:
        Shape():x(0), y(0) {}
        Shape(double i, double j):x(i), y(j) {}
        void set(double x0, double y0)
        {   x = x0; y = y0; }
        virtual double area()
        {   return 0;   }
};

class Circle : public Shape
{
    private:
        double radius;
    public:
        Circle():radius(0) {}
        Circle(double x0, double y0, double r);
        void set(double x0, double y0, double r);
        double area();
};

Circle::Circle(double x0, double y0, double r)
{
    Shape::set(x0, y0);
    radius = r;
}

void Circle::set(double x0, double y0, double r)
{
    Shape::set(x0, y0);
    radius = r;
}

double Circle::area()
{
    return 3.14 * radius * radius;
}

int main(void)
{
	Shape sp(1, 2), * p;
	Circle c(3, 4, 5);
	Shape &sp2 = c;//Shape类型的c的引用
	p = &sp;
	cout << p->area() << endl;
	p = &c;
	cout << p->area() << endl;
	cout << sp2.area() << endl;
	return 0;
}
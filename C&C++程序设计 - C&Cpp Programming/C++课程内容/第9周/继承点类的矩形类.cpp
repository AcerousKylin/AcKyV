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

class RECT:public POINT
{
    private:
        double width;
        double height;
    public:
        RECT():POINT(),width(0), height(0) {}
        RECT(double x0, double y0, double w, double h):POINT(x0, y0), width(w), height(h) {}
        void set(double x0, double y0, double w, double h)
        {
            POINT::set(x0 ,y0);
            width = w;
            height = h;
        }
        void show()
        {
            POINT::show();
            cout<<" width="<<width<<" height="<<height<<endl;
        }
};

int main(void)
{
	RECT a, b(1, 2, 10, 5);
	a.show();
	b.show();
	double x, y, w, h;
	std::cin >> x >> y >> w >> h;
	a.set(x, y, w, h);
	a.show();
	return 0;
}
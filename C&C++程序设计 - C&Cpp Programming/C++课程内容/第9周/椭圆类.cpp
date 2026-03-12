#include<iostream>
using namespace std;

class Ellipse
{
    private:
        int x;
        int y;
        double half_long;
        double half_short;
        const double Pi=3.14;
    public:
        Ellipse(int x0, int y0, double hs, double hl):x(x0), y(y0), half_short(hs), half_long(hl) {}
        double Area()
        {
            return Pi*half_long*half_short;
        }
};

int main(void)
{
	int a, b;
	double c, d;
	cin >> a >> b >> c >> d;
	Ellipse e(a, b, c, d);
	cout << e.Area() << endl;
	return 0;
}
#include<iostream>
using namespace std;

class Trapezium
{
    private:
        int left_above_x;
        int left_above_y;
        int left_below_x;
        int left_below_y;
        int right_above_x;
        int right_above_y;
        int right_below_x;
        int right_below_y;
    public:
        void initial(int lax, int lay, int rax, int ray, int lbx, int lby, int rbx, int rby);
        //void GetPosition(int &lax, int &lay, int &lbx, int &lby, int &rax, int &ray, int &rbx, int &rby);
        int Area();
};

void Trapezium::initial(int lax, int lay, int rax, int ray, int lbx, int lby, int rbx, int rby)
{
    left_above_x = lax;
    left_above_y = lay;
    left_below_x = lbx;
    left_below_y = lby;
    right_above_x = rax;
    right_above_y = ray;
    right_below_x = rbx;
    right_below_y = rby;
}

int Trapezium::Area()
{
    return (((right_above_x-left_above_x)+(right_below_x-left_below_x))*(left_above_y-left_below_y))/2;
}

int main(void)
{
	int a, b, c, d, e, f, g, h;
	cin >> a >> b >> c >> d >> e >> f >> g >> h;
	Trapezium t;
	t.initial(a, b, c, d, e, f, g, h);
	cout << t.Area() << endl;
	return 0;
}
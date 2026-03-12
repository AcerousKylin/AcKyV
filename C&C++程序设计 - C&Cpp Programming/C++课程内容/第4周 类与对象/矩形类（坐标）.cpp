#include<iostream>
#include<cmath>
using namespace std;

class RECT
{
    private:
        int left_up_x;
        int left_up_y;
        int right_down_x;
        int right_down_y;
    public:
        void set(int x1, int y1, int x2, int y2);
        int area();
        int perimeter();
        void showinfo();
        void show();
};

void RECT::set(int x1, int y1, int x2, int y2)
{
    left_up_x = x1;
    left_up_y = y1;
    right_down_x = x2;
    right_down_y = y2;
}

int RECT::area()
{
    int x, y;
    x = right_down_x-left_up_x;
    y = left_up_y-right_down_y;
    return abs(x*y);
}

int RECT::perimeter()
{
    int x, y;
    x = right_down_x-left_up_x;
    y = left_up_y-right_down_y;
    return abs(2*x)+abs(2*y);
}

void RECT::showinfo()
{
    cout << "(" << left_up_x << "," << left_up_y << "," << right_down_x << "," << right_down_y << ")" << endl;
}

void RECT::show()
{
    int x, y;
    x = right_down_x-left_up_x;
    y = left_up_y-right_down_y;
    int i, j;
    for (i=0; i<abs(y); i++)
    {
        for (j=0; j<abs(x); j++)
            cout << "*";
        cout << endl;
    }
}

int main(void)
{
	RECT a;
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	a.set(x1, y1, x2, y2);
	a.showinfo();
	cout << a.perimeter() << endl;
	cout << a.area() << endl;
	a.show();
	return 0;
}
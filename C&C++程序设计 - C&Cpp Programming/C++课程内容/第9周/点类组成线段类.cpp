#include<iostream>
#include<cmath>
using namespace std;

class Point
{
    private:
        double x;
        double y;
    public:
        Point():x(0), y(0) {}
        Point(double x0, double y0):x(x0), y(y0) {}
        void printPoint()
        {
            cout<<"Point:("<<x<<","<<y<<")"<<endl;
        }
        double output_x() {return x;}
        double output_y() {return y;}
};

class LineSegment
{
    private:
        Point point1;
        Point point2;
    public:
        LineSegment(Point p1, Point p2):point1(p1), point2(p2) {}
        double Calculate()
        {
            double _x = point1.output_x()-point2.output_x();
            double _y = point1.output_y()-point2.output_y();
            return sqrt(_x*_x+_y*_y);
        }
        void printLine()
        {
            cout<<"左端点 ";
            point1.printPoint();
            cout<<"右端点 ";
            point2.printPoint();
            cout<<"长度: "<<Calculate()<<endl;
        }
};

int main(void)
{
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	Point ps(x1, y1), pe(x2, y2);
	LineSegment ls(ps, pe);
	cout << "关于线段的信息: " << endl;
	ls.printLine();  //输出线段ls的信息
	return 0;
}
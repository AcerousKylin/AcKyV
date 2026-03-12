#include<iostream>
#include<cmath>
using namespace std;
const double PI = 3.14;

class Figures
{
    public:
        virtual void perimeter()=0;
        virtual void area()=0;
};

class Circle:public Figures
{
    private:
        double radius;
    public:
        Circle(double r):radius(r) {}
        void perimeter()
        {
            cout<<"Circle's perimeter:"<<2*PI*radius<<endl;
        }
        void area()
        {
            cout<<"Circle's area:"<<PI*radius*radius<<endl;
        }
};

class Square:public Figures
{
    private:
        double side;
    public:
        Square(double s):side(s) {}
        void perimeter()
        {
            cout<<"Square's perimeter:"<<4*side<<endl;
        }
        void area()
        {
            cout<<"Square's area:"<<side*side<<endl;
        }
};

int main(void)
{
    Figures* f;
    double r, s;
    cout<<"输入半径和边长"<<endl;
    cin>>r>>s;
    Circle cc(r);
    Square sq(s);

    f = &cc;
    f->perimeter();
    f->area();

    f = &sq;
    f->perimeter();
    f->area();

    return 0;
}
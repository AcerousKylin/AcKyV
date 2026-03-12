#include<iostream>
#include<cmath>
using namespace std;
const double PI = 3.1416;

class Base
{
    virtual void area()=0;
};

class rectangle:public Base
{
    private:
        double length;
        double width;
    public:
        rectangle(double l, double w):length(l), width(w) {}
        void area()
        {
            cout<<length*width<<endl;
        }
};

class circle:public Base
{
    private:
        double radius;
    public:
        circle(double r):radius(r) {}
        void area()
        {
            cout<<PI*radius*radius<<endl;
        }
};

int main(void)
{
    double l, w, r;
    cin>>l>>w>>r;
    rectangle rec(l, w);
    circle cir(r);
    cout<<"面积分别是："<<endl;
    rec.area();
    cir.area();
    return 0;
}
#include<iostream>
using namespace std;
const double Pi=3.14159;

class cylinder
{
    private:
        double radius;
        double height;
    public:
        cylinder(double r, double h);
        void vol();
};

cylinder::cylinder(double r, double h)
{
    radius = r;
    height = h;
}

void cylinder::vol()
{
    double v;
    v = Pi*radius*radius*height;
    cout<<v;
}

int main(void)
{
    double r, h;
    cin>>r>>h;
    cylinder c(r, h);
    c.vol();
    return 0;
}
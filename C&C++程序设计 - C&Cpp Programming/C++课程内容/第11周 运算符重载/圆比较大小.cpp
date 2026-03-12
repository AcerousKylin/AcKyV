#include<iostream>
using namespace std;

class Circle
{
    private:
        double radio;
    public:
        Circle(double r): radio(r) {}
        double getRadio();
        bool operator< (Circle c);
        bool operator<= (Circle c);
        bool operator== (Circle c);
        bool operator!= (Circle c);
        bool operator> (Circle c);
        bool operator>= (Circle c);
};

double Circle::getRadio()
{
    return radio;
}

bool Circle::operator< (Circle c)
{
    if (radio<c.getRadio())
        return 1;
    else
        return 0;
}

bool Circle::operator<= (Circle c)
{
    if (radio<=c.getRadio())
        return 1;
    else
        return 0;
}

bool Circle::operator== (Circle c)
{
    if (radio==c.getRadio())
        return 1;
    else
        return 0;
}

bool Circle::operator!= (Circle c)
{
    if (radio!=c.getRadio())
        return 1;
    else
        return 0;
}

bool Circle::operator> (Circle c)
{
    if (radio>c.getRadio())
        return 1;
    else
        return 0;
}

bool Circle::operator>= (Circle c)
{
    if (radio>=c.getRadio())
        return 1;
    else
        return 0;
}

int main(void)
{
    int r1, r2;
    cin>>r1>>r2;
    Circle c1(r1), c2(r2);
    cout<<boolalpha<<(c1<c2) <<endl;
    cout<<boolalpha<<(c1<=c2)<<endl;
    cout<<boolalpha<<(c1==c2)<<endl;
    cout<<boolalpha<<(c1!=c2)<<endl;
    cout<<boolalpha<<(c1>c2) <<endl;
    cout<<boolalpha<<(c1>=c2)<<endl;
}

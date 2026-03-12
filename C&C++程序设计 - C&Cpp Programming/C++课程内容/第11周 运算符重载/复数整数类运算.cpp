#include<iostream>
using namespace std;

class Complex;
Complex operator+ (Complex &a, Complex &b);
Complex operator+ (double c, Complex &d);
Complex operator+ (Complex &e, double f);

class Complex
{
    private:
        double real;
        double imag;
    public:
        Complex(): real(0), imag(0) {}
        Complex(double r, double i): real(r), imag(i) {}
        friend Complex operator+ (Complex &a, Complex &b);
        friend Complex operator+ (double c, Complex &d);
        friend Complex operator+ (Complex &e, double f);
        void display();
};

void Complex::display()
{
    cout<<"("<<real<<", "<<imag<<"i)"<<endl;;
}

Complex operator+ (Complex &a, Complex &b)
{
    return Complex(a.real+b.real, a.imag+b.imag);
}

Complex operator+ (double c, Complex &d)
{
    return Complex(c+d.real, d.imag);
}

Complex operator+ (Complex &e, double f)
{
    return Complex(f+e.real, e.imag);
}

int main(void)
{
    cout<<"输入复数C的实部和虚部"<<endl;
    double r, i;
    cin>>r>>i;
    Complex x(r, i);

    cout<<"输入整数a和b"<<endl;
    double a, b;
    cin>>a>>b;

    Complex x1, x2;
    x1 = x + a;
    x2 = b + x;

    cout<< "复数C=";
    x.display();

    cout<< "复数C+整数a=";
    x1.display();

    cout<< "整数b+复数C=";
    x2.display();
    return 0;
}

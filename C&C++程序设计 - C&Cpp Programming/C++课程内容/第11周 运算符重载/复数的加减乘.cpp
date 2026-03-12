#include <iostream>
using namespace std;

/********* Begin *********/

class Complex
{
	//复数类的声明
    private:
        float real;
        float imag;
    public:
        Complex(float r, float i): real(r), imag(i) {}
        Complex operator+ (Complex &a);
        Complex operator- (Complex &a);
        Complex operator* (Complex &a);
        void Print();
};

//复数类的定义

Complex Complex::operator+ (Complex &a)
{
    return Complex(a.real+real, a.imag+imag);
}

Complex Complex::operator- (Complex &a)
{
    return Complex(real-a.real, imag-a.imag);
}

Complex Complex::operator* (Complex &a)
{
    return Complex(real*a.real - imag*a.imag, real*a.imag + imag*a.real);
}

void Complex::Print()
{
    if (imag<0)
        cout<<real<<imag<<"i"<<endl;
    if (imag>0)
        cout<<real<<"+"<<imag<<"i"<<endl;
}

/********* End *********/

int main(void)
{
	float a, b, c, d;
	cin >> a >> b >> c >> d;
	Complex c1(a, b), c2(c, d);

	cout << "c1 = ";
	c1.Print();
	cout << "c2 = ";
	c2.Print();

	cout << "c1 + c2 = ";
	(c1 + c2).Print();
	cout << "c1 - c2 = ";
	(c1 - c2).Print();
	cout << "c1 * c2 = ";
	(c1 * c2).Print();
}
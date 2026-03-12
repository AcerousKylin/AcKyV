#include<iostream>
#include<cmath>
using namespace std;

class COMPLEX
{
    private:
        double real;
        double imag;
    public:
        void set(int r, int i);
        double getReal();
        double getImag();
        double module();
        COMPLEX add(COMPLEX);
        void show();
};

void COMPLEX::set(int r, int i)
{
    real = r;
    imag = i;
}

double COMPLEX::getReal()
{
    return real;
}

double COMPLEX::getImag()
{
    return imag;
}

double COMPLEX::module()
{
    return sqrt(pow(real,2)+pow(imag,2));
}

COMPLEX COMPLEX::add(COMPLEX a)
{
    COMPLEX b;
    b.real = real + a.real;
    b.imag = imag + a.imag;
    return b;
}

void COMPLEX::show()
{
    if (imag>0)
        cout << real << "+" << imag << "j" << endl;
    if (imag<0)
        cout << real << imag << "j" << endl;
}

int main() {
	COMPLEX a, b, c;
	double x, y;
	cin >> x >> y;
	a.set(x, y);
	cin >> x >> y;
	b.set(x, y);
	c = a.add(b);
	c.show();
	cout << c.getReal() << endl;
	cout << c.getImag() << endl;
	cout << c.module() << endl;
	return 0;
}
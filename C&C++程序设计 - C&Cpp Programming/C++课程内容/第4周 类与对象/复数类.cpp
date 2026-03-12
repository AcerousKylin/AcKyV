#include<iostream>
#include<cmath>
using namespace std;

class Complex
{
    private:
        int real;
        int imag;
    public:
        void init(int r, int i);
        double abscomplex();
        void disp();
};

void Complex::init(int r, int i)
{
    real = r;
    imag = i;
}

double Complex::abscomplex()
{
    return sqrt(pow(real,2)+pow(imag,2));
}

void Complex::disp()
{
    cout<<"复数的绝对值是："<<abscomplex()<<endl;
}

int main(void)
{
    int r, i;
    cin>>r>>i;
    Complex c;
    c.init(r, i);
    c.disp();
    return 0;
}
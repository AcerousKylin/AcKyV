#include<iostream>
using namespace std;

class A
{
    private:
        int init;
        int &reinit = init;
        const double Pi;
    public:
        A(int i, double n):init(i), Pi(n) {}
        void show();
};

void A::show()
{
    cout<<"int:"<<init<<endl;
    cout<<"int &:"<<reinit<<endl;
    cout<<"const :"<<Pi;
}

int main(void)
{
    int i;
    double n;
    cin>>i>>n;
    A z(i, n);
    z.show();
    return 0;
}
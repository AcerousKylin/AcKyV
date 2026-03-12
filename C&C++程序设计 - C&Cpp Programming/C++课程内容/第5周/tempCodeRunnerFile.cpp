#include<iostream>
using namespace std;

class Stock
{
    private:
        string stockcode;
        int quan;
        double price;
    public:
        Stock(string na, int q=1000, double p=8.98);
        void print();
};

Stock::Stock(string na, int q, double p)
{
    stockcode=na;
    quan=q;
    price=p;
}

void Stock::print()
{
    cout<<this->stockcode<<" ";
    cout<<this->quan<<" ";
    cout<<this->price<<" ";
    cout<<endl;
}

int main(void)
{
    string s1, s2;
    int i;
    double d;
    cin>>s1>>i>>d>>s2;
    Stock a(s1, i, d), b(s2);
    a.print();
    b.print();
    return 0;
}
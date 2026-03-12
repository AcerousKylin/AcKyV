#include<iostream>
using namespace std;

class book
{
    private:
        int qu;
        int price;
    public:
        book(int q, int p);
        void output();
};

book::book(int q, int p)
{
    qu = q;
    price = p;
}

void book::output()
{
    cout<<qu*price<<endl;
}

int main(void)
{
    book ob[5] = {book(1, 10), book(2, 20), book(3, 30), book(4, 40), book(5, 50)};
    int i;
    for (i=4; i>=0; i--)
    {
        ob[i].output();
    }
    return 0;
}
#include<iostream>
using namespace std;

class FRACTION
{
    private:
        int numerator;
        int denominator;
    public:
        void set(int x, int y);
        double real();
        void show();
    private:
        void reduce()
        {
            if (numerator!=0)
            {
                int i;
                for (i=2; i<(numerator<denominator?denominator:numerator); i++)
                {
                    if(numerator%i==0 && denominator%i==0)
                        numerator /= i;
                        denominator /= i;
                }
            }
        }
};

void FRACTION::set(int x, int y)
{
    numerator = x;
    denominator = y;
    reduce();
}

double FRACTION::real()
{
    return numerator/denominator;
}

void FRACTION::show()
{
    if (numerator>0 && denominator<0)
    {
        numerator = -numerator;
        denominator = - denominator;
    }
    cout<<numerator<<"/"<<denominator<<endl;
}

int main(voie)
{
	FRACTION a;
	int x, y;
	cin >> x >> y;
	a.set(x, y);
	a.show();
	cout << a.real() << endl;
	return 0;
}
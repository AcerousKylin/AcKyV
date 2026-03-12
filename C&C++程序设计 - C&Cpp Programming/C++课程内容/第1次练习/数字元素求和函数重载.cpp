#include<iostream>
using namespace std;

int input(int* p);
int input(double* p);
int mysum(int* p, int n);
double mysum(double* p,int n);

int main(void)
{
	int ai[100];
	double ad[100];
	int sumi;
	double sumd;
	int ni = input(ai);
	int nd = input(ad);
	sumi = mysum(ai, ni);
	sumd = mysum(ad, nd);
	cout << sumi << " " << sumd << endl;
	return 0;
}

int input(int* p)
{
    int i=0;
    do
    {
        cin>>p[i];
    }while(p[i++]!=-9999);
    return i-1;
}

int input(double* p)
{
    int i=0;
    do
    {
        cin>>p[i];
    }while(p[i++]!=-9999);
    return i-1;
}

int mysum(int* p, int n)
{
    int sum=0, i;
    for (i=0; i<n; i++)
        sum += p[i];
    return sum;
}

double mysum(double* p,int n)
{
    double sum=0;
    int i;
    for (i=0; i<n; i++)
        sum += p[i];
    return sum;
}
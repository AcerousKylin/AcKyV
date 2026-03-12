#include<iostream>
using namespace std;

int input(int* p);
int input(double* p);
void print(int* p, int n);
void print(double* p, int n);

int main(void)
{
	int a[100];
	double b[100];
	int lena = input(a);
	int lenb = input(b);
	print(a, lena);
	print(b, lenb);
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

void print(int* p, int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        cout<<*(p+i);
        if (i!=n-1)
            cout<<" ";
    }
    cout<<endl;
}

void print(double* p, int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        cout<<*(p+i);
        if (i!=n-1)
            cout<<" ";
    }
    cout<<endl;
}
#include<iostream>
using namespace std;

int input(int* p)
{
    int n=0;
    cin>>*p;
    while(*p!=-9999)
    {
        cin>>*(++p);
        n++;
    }
    return n;
}

int input(double* p)
{
    int n=0;
    cin>>*p;
    while(*p!=-9999)
    {
        cin>>*(++p);
        n++;
    }
    return n;
}

void reverse(int* p, int n)
{
    int i;
    for (i=0; i<n/2; i++)
    {
        int temp;
        temp = p[i];
        p[i] = p[n-i];
        p[n-i] = temp;
    }
}

void reverse(double* p, int n)
{
    int i;
    for (i=0; i<n/2; i++)
    {
        int temp;
        temp = p[i];
        p[i] = p[n-i];
        p[n-i] = temp;
    }
}

void print(int* p, int n)
{
    int i;
    for (i=0; i<n; i++)
        cout<<p[i];
}

void print(double* p， int n)
{
    int i;
    for (i=0; i<n; i++)
        cout<<p[i];
}

int main(void)
{
	int ai[100];
	double ad[100];
	int ni, nd;
	ni = input(ai);
	nd = input(ad);
	reverse(ai, ni);
	reverse(ad, nd);
	print(ai, ni);
	print(ad, nd);
	return 0;
}
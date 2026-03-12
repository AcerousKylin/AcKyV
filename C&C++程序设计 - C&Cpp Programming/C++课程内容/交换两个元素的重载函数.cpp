#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swap(double* a, double* b)
{
    double temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swap(char a, char b)
{
    char temp;
    temp = a;
    a= b;
    b = temp;
}

void swap(int* a, int &n, int* b, int &m)
{
    int i;
    for (i=0; i<100; i++)
    {
        int temp;
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
    int temp;
    temp = n;
    n = m;
    m = temp;
}

void swap(char* a, char* b)
{
    int i;
    for (i=0; i<100; i++)
    {
        char temp;
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void print(int* p, int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        cout<<p[i];
        if (i!=n-1)
            cout<<" ";
    }
    cout<<endl;
}

void print(char* p, int n)
{
    int i;
    for (i=0; i<n; i++)
        cout<<p[i];
    cout<<endl;
}

int main(void)
{
	int a, b;
	double da, db;
	int aa[100], ab[100];
	char s1[100], s2[100];
	int n, m;
	int i;
	//输入
	cin >> a >> b;
	cin >> da >> db;
	//输入数组
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> aa[i];
	}
	cin >> m;
	for (i = 0; i < m; i++) {
		cin >> ab[i];
	}
	cin >> s1 >> s2;
	//交换
	swap(a, b);
	swap(da, db);
	swap(aa, n, ab, m);
	swap(s1, s2);
	//输出
	cout << a << " " << b << endl;
	cout << da << " " << db << endl;
	print(aa, n);
	print(ab, m);
	cout << s1 << " " << s2 << endl;
	return 0;
}
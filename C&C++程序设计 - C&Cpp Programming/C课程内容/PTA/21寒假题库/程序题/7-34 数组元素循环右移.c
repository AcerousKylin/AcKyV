#include <stdio.h>
#define MAXN 100

void ArrayShift( int a[], int n, int m )
{
	if (m>n)
		m %= n;
	int i=n-1, j;
	int b[n*n];
	for(i=n-m, j=0; i<n; i++, j++) // 将后m个数转存
		b[j]=a[i];
	while(i>=m) //  将前面的数按规则后移
	{
		a[i] = a[i-m];
		i--;
	}
	for(i=0, j=0; i<m; i++, j++) // 将后m个数补在前面
		a[i] = b[j];
}

int main(void)
{
    int a[MAXN];
    int i, n, m;
    scanf("%d %d", &n, &m);
    for (i=0; i<n; i++)
        scanf("%d", &a[i]);
    ArrayShift(a, n, m);
    for (i=0; i<n; i++)
    {
        printf("%d", a[i]);
        if (i!=n-1)
            printf(" ");
    }
    return 0;
}
#include <stdio.h>
#define MAXN 10

void ArrayShift( int a[], int n, int m );

int main()
{
    int a[MAXN], n, m;
    int i;

    scanf("%d %d", &n, &m);
    for ( i = 0; i < n; i++ ) scanf("%d", &a[i]);

    ArrayShift(a, n, m);

    for ( i = 0; i < n; i++ ) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}

/* 你的代码将被嵌在这里 */

// 2m-1<=n时适用
void ArrayShift( int a[], int n, int m )
{
    int *pa=a, i, temp1, temp2;
    if (m>n)
        m %= n;
    if (m<n)
    {
        for (i=0; i<m; i++)
        {
            temp1 = pa[m+i];
            pa[m+i] = pa[i];
            temp2 = pa[n-m+i];
            pa[n-m+i] = temp1;
            pa[i] = temp2;
        }
    }
}

//转录
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
		a[i]=a[i-m];
		i--;
	}
	for(i=0, j=0; i<m; i++, j++) // 将后m个数补在前面
		a[i]=b[j];
}

#include<stdio.h>
#include<math.h>
int mi(int n,int a)
{
	int number=1;
	while(a--)
    {
		number *= n;
	}
	return number;
}
int main()
{  	
	int n, number, t, i;
	scanf("%d",&n);
	for(i=mi(10,n-1); i<mi(10,n)-1; i++)
    {
        number = 0;
        t = i;
		while(t)
        {
			int ge = t%10;
			number += mi(ge,n);
			t /= 10;
		}
		if(number==i)
			printf("%d\n", i);
	}
 	return 0;
}

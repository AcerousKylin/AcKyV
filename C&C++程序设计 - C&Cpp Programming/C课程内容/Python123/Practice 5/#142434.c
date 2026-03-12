#include<stdio.h>
void Reorder(void)
{
    int i, j, k; extern int m[5];
    for (i=1; i<=4; i++)
    {
        for (j=i+1; j<=4; j++)
        {
            if (m[i]<m[j])
            {
                k = m[i];
                m[i] = m[j];
                m[j] = k;
            }
        }
    }
}
int m[5]={0};
int main(void)
{
    int n, i, increasing, reverse;
    extern int m[5];
    scanf("%d", &n);
    while (n!=6174)
    {
        for (i=4; i<=1; i--)
        {
            m[i] = n % 10;
            n /= 10;
        }
        Reorder();
        increasing = m[1]*1000+m[2]*100+m[3]*10+m[4];
        reverse = m[4]*1000+m[3]*100+m[2]*10+m[1];
        n = increasing - reverse;
        printf("%d%d%d%d-%d%d%d%d=%d\n", m[1], m[2], m[3], m[4], m[4], m[3], m[2], m[1], n);
    }
    return 0;
}
#include<iostream>
#include<cmath>
using namespace std;

void solution(void)
{
    int n, m;
    cin>>n>>m;
    char s[n][m];
    for (int i=0; i<n; i++)
        scanf("%s", &s[i]);
    int min=250;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int sum=0;
            for (int k=0; k<m; k++)
            {
                sum += abs(s[i][k]-s[j][k]);
            }
            if (sum<min)
                min = sum;
        }
    }
    printf("%d\n", min);
}

int main(void)
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        solution();
    }
    return 0;
}
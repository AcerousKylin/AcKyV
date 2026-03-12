#include<bits/stdc++.h>
using namespace std;

const int N = 30;

int n, k, sum=0;
int number[N];
int ans=0;

bool is_prime(int u)
{
    if (u < 2)
        return false;
    for (int i = 2; i*i <= u; i++)
    {
        if (u % i == 0)
            return false;
    }
    return true;
}

void dfs(int queue, int last)
{
    if (queue == k)
    {
        // printf("sum = %d\n", sum);
        if (is_prime(sum))
            ans++;
        return;
    }

    for (int i = last; i <= n - k + queue; i++)
    {
        sum += number[i];
        dfs(queue+1, i+1);
        sum -= number[i];
    }
}

int main(void)
{
    cin >> n >> k;
    
    for (int i = 0; i < n; i++)
        cin >> number[i];

    sort(number, number+n);
    dfs(0, 0);

    printf("%d", ans);

    return 0;
}
//斐波那契数列，输出前n项，每位占6位宽
int main(void)
{
    int i, n; int f[20]={1,1};
    scanf("%d", &n);
    for(i=2; i<=n; i++)
        f[i] = f[i-1] + f[i-2];
    for (i=0; i<=n-1; i++)
        printf("%6d", f[i]);
    return 0;
}
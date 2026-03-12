#include<stdio.h>
int main(void)
{
    int n[20], i, flag =1; char s[20];
    for(i=0; s[i]!='='; i++)
        scanf("%d%c", &n[i], &s[i]);
    for (i=0; s[i]!='='; i++)
    {
        switch (s[i])
        {
            case '+' :
                n[i+1] = n[i] + n[i+1];
                break;
            case '-' :
                n[i+1] = n[i] - n[i+1];
                break;
            case '*' :
                n[i+1] = n[i] * n[i+1];
                break;
            case '/' :
                if (n[i+1]==0)
                {
                    flag=0;
                    break;
                }
                n[i+1] = n[i] / n[i+1];
                break;
            case '=' :
                break;
            default :
                flag=0;
                break;
        }
        if (flag==0)
            break;
    }
    if (flag==0)
        printf("ERROR");
    else
        printf("%d", n[i]);
    return 0;
}
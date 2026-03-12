#include<math.h>
int main(void)
{
    int set, guess, n, i;
    scanf("%d %d", &set, &n);
    for(i=1; i<=n; i++)
    {
        scanf("%d", &guess);
        if (guess<0)
        {
            printf("Game Over");
            return 0;
        } 
        else if (guess>set)
            printf("Too big\n");
        else if (guess<set)
            printf("Too small\n");
        else if (guess==set)
        {
            switch (i)
            {
                case 1 :
                    printf("Bingo!");
                    break;
                case 2:
                case 3:
                    printf("Lucky You!");
                    break;
                default :
                    printf("Good Guess!");
            }
            return 0;
        }
    }
    printf("Game Over");
    return 0;
}
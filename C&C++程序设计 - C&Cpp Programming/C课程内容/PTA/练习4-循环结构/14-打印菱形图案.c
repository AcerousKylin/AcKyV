//打印菱形图案
#include<stdio.h>
int main(void)
{
    int input;
    int line, blank, star;
    int lines, blanks, stars;
    scanf("%d", &input);
    for (line=1; line<=input; line++)
    {
        if (line<=input/2+1)
        {
            for (blank=input-(2*line-1); blank>=1; blank--)
            {
                putchar(' ');
            }
            for (star=1; star<=line*2-1; star++)
            {
                if (star==line*2-1)
                    printf("* \n");
                else if (star<line*2-1)
                    printf("* ");
                else;
            }
        }
        else if (line>input/2+1&&line<=input)
        {
            for (blanks=(line-(input/2+1))*2; blanks>=1; blanks--)
            {
                putchar(' ');
            }
            for (stars=(input-line)*2+1; stars>=1; stars-=1)
            {
                if (stars==1)
                    printf("* \n");
                else if (stars>=1)
                    printf("* ");
                else;
            }
        }
        else printf("I AM MADNESS.");
    }
    return 0;
}

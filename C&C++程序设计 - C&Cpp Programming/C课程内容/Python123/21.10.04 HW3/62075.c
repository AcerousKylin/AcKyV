#include<stdio.h>
#include<math.h>
int main(void)
{
    int w;
    float bmi, h;
    scanf("%d,%f", &w, &h);
    bmi = w/pow(h, 2);
    if (bmi<18.5) printf("体重过低");
    else if (bmi>=18.5&&bmi<22.9)
        printf("体重正常");
    else if (bmi>=22.9&&bmi<=24.9)
        printf("超重");
    else printf("肥胖");
    return 0;
}
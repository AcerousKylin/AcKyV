#include<stdio.h>
int main(void)
{
    int n, flag;
    scanf("%d", &n);
    flag = (n%2==0 && n%3==0)?1:0;
        printf("%d divisible by 2 and 3? %d\n", n, flag);
    flag = (n%2==0 || n%3==0)?1:0;
        printf("%d divisible by 2 or 3? %d\n", n, flag);
    flag = ((n%2==0 && n%3!=0) || (n%2!=0 && n%3==0))?1:0;
        printf("%d divisible by 2 or 3, but not both? %d", n, flag);
    return 0;
}
/*
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    printf("%d%s%d\n", n, " divisible by 2 and 3? ", 
	       (n % 2 == 0 && n % 3 == 0));
    printf("%d%s%d\n", n, " divisible by 2 or 3? ", 
	       (n % 2 == 0 || n % 3 == 0));
    printf("%d%s%d\n", n, " divisible by 2 or 3, but not both? ", 
	      ((n % 2 == 0 || n % 3 == 0) && !(n % 2 == 0 && n % 3 == 0)));
    return 0;
}
*/
//逻辑运算式可以直接输出值
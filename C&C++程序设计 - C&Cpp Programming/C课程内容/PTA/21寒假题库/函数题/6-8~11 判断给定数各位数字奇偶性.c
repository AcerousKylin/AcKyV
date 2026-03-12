// 判断两位均为偶数
#include <stdio.h>
int  result(int *p);
int main()
{

  int n=0, flag=-1;
  scanf("%d", &n); 
  flag = result(&n);
  printf("%d", flag);

  return 0;

}

/* 请在这里填写答案 */

int  result(int *p)
{
    int single, ten;
    single = *p % 10;
    ten = *p / 10;
    if (single%2==0 && ten%2==0)
        return 1;
    else
        return 0;
}

// 判断两位均为奇数

int result(int *p)
{
    int single, ten;
    single = *p % 10;
    ten = *p / 10;
    if (single%2==1 && ten%2==1)
        return 1;
    else
        return 0;
}

// 判断两位数十奇个偶

int result(int *p)
{
    int single, ten;
    single = *p % 10;
    ten = *p / 10;
    if (single%2==0 && ten%2==1)
        return 1;
    else
        return 0;
}

// 判断两位数个奇十偶

int result(int *p)
{
    int single, ten;
    single = *p % 10;
    ten = *p / 10;
    if (single%2==1 && ten%2==0)
        return 1;
    else
        return 0;
}
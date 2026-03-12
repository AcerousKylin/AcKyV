#include <stdio.h>
int main(){
  int a1,a2;
  char c1,c2;
  scanf("%d%c",&a1,&c1);
  scanf("%d %c",&a2,&c2);
  printf("a1=%d,c1=%c,c1=%d\n",a1,c1,c1);
  printf("a2=%d,c2=%c,c2=%d\n",a2,c2,c2);
  return 0;
}
/*
若输入:
5  6  A
输出结果为:
a1=5,c1= ,c1=32
a2=6,c2=A,c2=65
证明:
1.在没有对应类型输入时，相关的格式说明符无法赋值
2.字符变量可以直接以整型输出ASCII码值
*/
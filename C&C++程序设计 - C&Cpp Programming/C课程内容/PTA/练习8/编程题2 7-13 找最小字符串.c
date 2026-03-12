/*本题要求编写程序，针对输入的N个字符串，输出其中最小的字符串。

输入格式：
输入第一行给出正整数N；随后N行，每行给出一个长度小于80的非空字符串，其中不会出现换行符，空格，制表符。

输出格式：
在一行中用以下格式输出最小的字符串：

Min is: 最小字符串

输入样例：
5
Li
Wang
Zha
Jin
Xian
结尾无空行

输出样例：
Min is: Jin
结尾无空行
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
	char a[10000][80], temp[80];
	int n, i, j, min;
	scanf("%d", &n);
	getchar(); // 注意数字后面的\n
	for(i=0; i<n; i++)
		gets(a[i]); // 按行循环存入二维字符串
	for(i=0; i<n-1; i++)
	{
		min = i; // 重置第i个为最小字符串，进行逐位比较
		for(j=i+1; j<n; j++) // 选择法排序
			if(strcmp(a[min], a[j])>0) // 按行直接比较，小的变为min
				min = j;
			if(min!=i) // 如果最小字符串不再是第i个，把其转移到i上，排序
			{
				strcpy(temp,a[min]);
				strcpy(a[min],a[i]);
				strcpy(a[i],temp);
			}
	}
	printf("Min is: %s",a[0]); // 排完序第一个就是最小的
	return 0;
}


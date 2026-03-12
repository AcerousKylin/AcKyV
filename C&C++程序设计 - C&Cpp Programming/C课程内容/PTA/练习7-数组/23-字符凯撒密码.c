/*
为了防止信息被别人轻易窃取，需要把电码明文通过加密方式变换成为密文。输入一个以回车符为结束标志的字符串（少于80个字符），再输入一个整数offset，用凯撒密码将其加密后输出。恺撒密码是一种简单的替换加密技术，将明文中的所有字母都在字母表上偏移offset位后被替换成密文，当offset大于零时，表示向后偏移；当offset小于零时，表示向前偏移。

输入格式:
输入第一行给出一个以回车结束的非空字符串（少于80个字符）；第二行输入一个整数offset。

输出格式:
输出加密后的结果字符串。

输入样例1:
Hello Hangzhou
2
结尾无空行

输出样例1:
Jgnnq Jcpibjqw
结尾无空行

输入样例2:
a=x+y
-1
结尾无空行

输出样例2:
z=w+x
结尾无空行
*/

#include<stdio.h>
#include<string.h>
int main(void)
{
    char code[100], small[26], big[26]; // 密码原文,小写字母转译本,大写字母转译本
    char *pc; // 用于指向code的指针
    int offset, i; // 偏移量和循环用计数器
    gets(code); // 获取密码原文
    scanf("%d", &offset); // 输入偏移量
    offset %= 26; // 将偏移量简单化处理,便于运算
    for (i=0; i<26; i++)
    { // 将所有大小写字母存入对应的转译本
        small[i] = 'a' + i;
        big[i] = 'A' + i;
    }
    for (pc=code; *pc!='\0'; pc++)
    {
        if (*pc>=65 && *pc<= 90) // 当密码为大写字母
        {
            *pc -= 65; // 先转码为数组下标
            if (*pc+offset>25) // 如果下标+偏移量超过单个字母表
                printf("%c", big[*pc+offset-26]); // 下标-26,输出对应字母
            if (*pc+offset>=0 && *pc+offset<=25) // 如果在单个字母表内
                printf("%c", big[*pc+offset]); // 下标不变,输出对应字母
            if (*pc+offset<0) // 如果小于单个字母表
                printf("%c", big[*pc+offset+26]); // 下标+26,输出对应字母
        }
        else if (*pc>=97 && *pc<=122) // 当密码为小写字母
        {
            *pc -= 97; // 先转码为数组下标
            if (*pc+offset>25)// 如果下标+偏移量超过单个字母表
                printf("%c", small[*pc+offset-26]); // 下标-26,输出对应字母
            if (*pc+offset>=0 && *pc+offset<=25) // 如果在单个字母表内
                printf("%c", small[*pc+offset]); // 下标不变,输出对应字母
            if (*pc+offset<0) // 如果小于单个字母表
                printf("%c", small[*pc+offset+26]); // 下标+26,输出对应字母
        }
        else
            printf("%c", *pc); // 如果不是字母,原封不动输出
    }
    return 0;
}
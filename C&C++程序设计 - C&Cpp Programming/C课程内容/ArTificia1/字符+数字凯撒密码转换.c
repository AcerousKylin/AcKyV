#include<stdio.h>
#include<math.h>
#include<string.h>
int main(void)
{
    char code[100], small[26], big[26]; // 密码原文,小写字母转译本,大写字母转译本
    char *pc; // 用于指向code的指针
    int offset, c_offset, n_offset, i; // 偏移量和循环用计数器
    printf("//Caesar: Plz enter yr password, then enter the offset on the 2nd line:\n");
    printf("//(Password limit 100 ;P)\n");
    gets(code); // 获取密码原文
    scanf("%d", &offset); // 输入偏移量
    printf("//Caesar: Oh my dear friend, here's the code:\n");
    c_offset = offset % 26; n_offset = offset % 10; // 将字母偏移量简单化处理,便于运算
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
            if (*pc+c_offset>25) // 如果下标+偏移量超过单个字母表
                printf("%c", big[*pc+c_offset-26]); // 下标-26,输出对应字母
            if (*pc+c_offset>=0 && *pc+c_offset<=25) // 如果在单个字母表内
                printf("%c", big[*pc+c_offset]); // 下标不变,输出对应字母
            if (*pc+c_offset<0) // 如果小于单个字母表
                printf("%c", big[*pc+c_offset+26]); // 下标+26,输出对应字母
        }
        else if (*pc>=97 && *pc<=122) // 当密码为小写字母
        {
            *pc -= 97; // 先转码为数组下标
            if (*pc+c_offset>25)// 如果下标+偏移量超过单个字母表
                printf("%c", small[*pc+c_offset-26]); // 下标-26,输出对应字母
            if (*pc+c_offset>=0 && *pc+c_offset<=25) // 如果在单个字母表内
                printf("%c", small[*pc+c_offset]); // 下标不变,输出对应字母
            if (*pc+c_offset<0) // 如果小于单个字母表
                printf("%c", small[*pc+c_offset+26]); // 下标+26,输出对应字母
        }
        else if (*pc>=48 && *pc<=57)
        {
            *pc -= 48;
            if (*pc+n_offset>9)
                printf("%d", *pc+n_offset-10);
            if (*pc+n_offset>=0 && *pc+n_offset<=9)
                printf("%d", *pc+n_offset);
            if (*pc+n_offset<0)
                printf("%d", *pc+n_offset+10);
        }
        else
            printf("%c", *pc); // 如果既不是字母,也不是数字,原封不动输出
    }
    return 0;
}
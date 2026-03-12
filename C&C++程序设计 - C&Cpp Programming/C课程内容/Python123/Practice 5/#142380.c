//从以#结尾的字符串中提取数字并求和
//switch版
#include<stdio.h>
int main(void)
{
    int i, number, sum=0; char ch;
    while ((ch=getchar())!='#')
    {
        switch (ch)
        {
            case '0' : number=0; break;
            case '1' : number=1; break;
            case '2' : number=2; break;
            case '3' : number=3; break;
            case '4' : number=4; break;
            case '5' : number=5; break;
            case '6' : number=6; break;
            case '7' : number=7; break;
            case '8' : number=8; break;
            case '9' : number=9; break;
            default : continue;
        }
        sum += number;
    }
    printf("%d", sum);
    return 0;
}

//if版
#include<stdio.h>
int main(){
    char ch;
    int sum=0,num;
    while((ch=getchar())!='#')
    {
        if(ch>='0' && ch<='9')
        {
            num=ch-'0';
            sum+=num;
        }
    }
    printf("%d\n",sum);
    return 0;
}
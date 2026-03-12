#include<stdio.h>
#include<string.h>

#define MAX_CACHE 255;
#define MAX_TOKEN 10;

int codes[1024];    // 存放词法分析结果的种别码
int current_index = 1;  // codes的指针

// 声明各函数
int Sentence();
int Expression();
int Expression_Extend();
int Judgement();
int Variety();
int Variety_Postfix();
int Item();
int Item_Extend();
int Factor();
void Error(char msg);

int Sentence()  // <语句>
{
    printf("Sentence -> ");
    if (codes[current_index] == 20 || codes[current_index] == 31)
    {   // 如果是标识符或(，则表明是<表达式>
        return Expression();
    }
    else if (codes[current_index] == 9)
    {   // 如果是关键字if，则表明是<判断语句>
        return Judgement();
    }
    else
    {
        Error('s');
        return 0;
    }
}

int Expression()    // <表达式>
{
    printf("Expression -> ");
    if (codes[current_index] == 20 || codes[current_index] == 31)   // 如果是标识符或(，则表明这是一个<项>
    {
        if (Item() == 1)    // 如果当前token能推出项
        {
            printf("Item -> ");
            current_index++;    // 指针后移
            return Expression_Extend(); // 检查<表达式'>并返回结果
        }
        else
        {
            Error('e');
            return 0;
        }
    }
    else
    {
        Error('e');
        return 0;
    }
}

int Expression_Extend() // <表达式'>
{
    printf("ExpressionE -> ");
    if (codes[current_index] == 22) //若当前token是+
    {
        current_index++;    // 指针后移
        if(Item() == 1) // 是否是<项>
        {   // 是则检查后续语法
            current_index++;    // 指针后移
            return Expression_Extend(); // 检查<表达式'>并返回结果
        }
        else
        {   // 不是则输出错误信息并返回结果
            Error('i');
            return 0;
        }
    }
    else if (codes[current_index+1] == 32)  // 若当前token的FOLLOW是)
    {
        printf("#\n");  // <语句>判断成功
        current_index++; // 指针后移
        return 1;
    }
    else
    {
        Error('E');
        return 0;
    }
}

int Judgement()
{
    printf("Judgement -> ");
    current_index++;    // 指向if的下一个token
    if (Expression() == 1)
    {
        current_index++;    // 指针后移
        if (codes[current_index] == 10) // 若当前token是else
        {   // 检测一个语句
            return Sentence();  // 检测<语句>并返回结果
        }
        else
        {   // 否则结束
            printf("#\n");  // <语句>判断成功
            return 1;
        }
    }
    else
    {
        Error('j');
        return 0;
    }
}

int Variety()
{
    if (codes[current_index] == 20) // 若当前token是标识符
    {
        printf("i -> ");
        current_index++;    // 指针后移
        return Variety_Postfix();   // 检查<变量后缀>并返回结果
    }
    else
    {
        Error('v');
        return 0;
    }
}

int Variety_Postfix()
{
    if (codes[current_index] == '[')
    {
        printf("VarietyP -> ");
        printf("[ -> ");
        if (Expression() == 1)
        {
            printf("] -> ");
            return 1;
        }
        else
        {
            Error('V');
            return 0;
        }
    }
    else
        return 1;
}

int Item()
{
    printf("Item -> ");
    if (codes[current_index] == 20 || codes[current_index] == 31)   // 若当前token是
    {
        if (Factor() == 1)
        {
            printf("Factor -> ");
            current_index++;    // 指针后移
            return Item_Extend();   // 检查<项'>并返回结果
        }
        else
        {
            Error('i');
            return 0;
        }
    }
    else
    {
        Error('i');
        return 0;
    }
}

int Item_Extend()
{
    printf("ItemE -> ");
    if (codes[current_index] == 24) // 若当前token是*
    {
        current_index++;    // 指针后移
        if (Factor())
        {
            current_index++;    // 指针后移
            return Item_Extend();   // 检查<项'>并返回结果
        }
        else
        {
            Error('I');
            return 0;
        }
    }
    else
    {
        printf("#\n");  // <语句>判断成功
        return 1;
    }
}

int Factor()
{
    printf("Factor -> ");
    if (codes[current_index] == 20) // 若当前token是标识符
    {
        return Variety();   // 检查<变量>并返回结果
    }
    else if (codes[current_index] == 32)    // 若当前token是(
    {
        printf("( -> ");
        current_index++;    // 指针后移
        if (Expression())   // 检查<表达式>
        {
            if (codes[current_index+1] == 32)   // 若当前token的FOLLOW是)
            {
                printf(") -> ");
                return 1;
            }
            else
            {
                Error('f');
                return 0;
            }
        }
        else
        {
            Error('e');
            return 0;
        }
    }
    else
    {
        Error('f');
        return 0;
    }
}

void Error(char msg)    // 报错结果打印
{
    printf("Error(%c)\n", msg);
}

int main(void)
{
    printf("Grammar analyzer start to run...\n");
    char source[25], result[25];
    printf("Please enter the source TOKEN filename with postfix:\n");
    scanf("%s", source);

    // 这里读取的是.txt文件，直接使用r作为读取参数
    FILE *input = fopen(source, "r+");

    // 读取文件内容
    printf("Start to scan the source.\n");
    char buffer[10];
    int length;
    for (length=0; fgets(buffer, 10, input) != NULL; length++)  // 获取有效token数量
    {
        int temp_code;  // 用于暂时存放token的种别码
        int flag = sscanf(buffer, "%*[^ ]%d%*[(]", &temp_code); // 提取token中的种别码，返回成功与否
        if (flag == 0)
        {
            length--;
            printf("[Error] Token reading failed.\n");
            continue;
        }
        else if (temp_code == 40)   // 跳过词法分析的错误
            length--;
        else
            codes[length] = temp_code;
    }

    while (current_index < length)  // 根据长度进行检测
    {
        if (Sentence() == 0)
            printf("[Warning] An error is found in grammar.\n");
        else
            printf("[Info] A sentence is detected correctly.\n");
        current_index++;    // 每次检测完毕，指针后移指向新的token
    }

    printf("[Info] Grammar analysis finished.\n");

    return 0;
}
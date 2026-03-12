#include<stdio.h>
#include<string.h>

#define MAX_KEYS 19
#define MAX_WORD 255

char big_buffer[1024];
char* current_char = NULL;

struct Keyword
{
    char key[10];
    int code;
} keywords[100];

char initKeys[100][10] = {
    "main", "void", "int", "short", "long",
    "double", "float", "char","if", "else",
    "switch", "case", "default", "break", "do",
    "while", "for", "continue", "struct"
};

void initKeywords()
{
    for (int i=0; i<MAX_KEYS; i++)
    {
        strcpy(keywords[i].key, initKeys[i]);
        keywords[i].code = i+1;
    }
}

int LetterTrigger()
{
    if ( (*current_char >= 'a' && *current_char <= 'z') || 
    (*current_char >= 'A' && *current_char <= 'Z') )
        return 1;
    else 
        return 0;
}

int KeywordAnalyzer(char word[])
{
    int i;
    for (i=0; i<MAX_KEYS; i++)
        if ( (strcmp(keywords[i].key, word)) == 0)
            break;
    if (i < MAX_KEYS)
        return keywords[i].code;
    else
        return 0;
}

int DigitTrigger()
{
    if (*current_char >= '0' && *current_char <= '9')
        return 1;
    else 
        return 0;
}

int SymbolTrigger()
{
    if (*current_char == '+' || *current_char == '=' ||
    *current_char == '<' || *current_char == '>' ||
    *current_char == '*' || *current_char == '/' ||
    *current_char == '%' || *current_char == ';' ||
    *current_char == '{' || *current_char == '}' ||
    *current_char == '(' || *current_char == ')')
        return 1;
    else 
        return 0;
}

void FormattingOutput(char source[], int code, FILE *output)
{
    // 建立临时缓冲区
    char cache[50];
    // 使用格式化输出并存储到缓冲区中
    sprintf(cache, "(%s, %d)\n", source, code);
    // 追加到输出文件中
    fputs(cache, output);
}

void Analyze(FILE *input, FILE *output)
{
    // 输出文件的首行说明
    fputs("(Word, Species Code)\n", output);

    // 词法分析程序结束的标志，取决于读入方式，此处用字符串结尾，而非EOF
    while ( *current_char != '\0' )
    {
        // 对空格、制表符和换行操作进行跳过
        if (*current_char == ' ' || *current_char == '\t' || *current_char == '\n'|| *current_char == '\r')
            printf("Find a space, table or enter, ignore.\n");

        // 对头文件进行跳过
        else if (*current_char == '#')
        {
            printf("Find a Header, ignore.\n");
            while (*current_char++ != '\n');
        }
        
        // 对字符-标识符&关键字进行检查
        else if (*current_char == '_' || LetterTrigger())
        {
            // 标识符/关键字缓存和其指针
            int index = 0;
            char cache[MAX_WORD];

            printf("Find a key word, processing...\n");

            // 由于后续判断条件不同，先将第一位进行缓存和移位
            cache[index++] = *(current_char++);
            // 再进一步组合标识符/关键字
            while (LetterTrigger() | DigitTrigger() | *current_char == '_')
                cache[index++] = *(current_char++);
            
            // 回退循环结束的指针移动
            current_char--;
            // 给缓存中的字符串结尾添加\0
            cache[index] = '\0';

            // 检查是否为关键字
            if (KeywordAnalyzer(cache))
                FormattingOutput(cache, KeywordAnalyzer(cache), output);
            // 否则将标识符直接输出
            else
                FormattingOutput(cache, 20, output);
        }

        // 检查是否为数字
        else if (DigitTrigger())
        {
            // 数字缓存和其指针
            int index = 0;
            char cache[MAX_WORD];

            printf("Find a digit, processing...\n");

            while (DigitTrigger())
                cache[index++] = *(current_char++);   
            
            // 回退循环结束的指针移动
            current_char--;
            // 给缓存中的字符串结尾添加\0
            cache[index] = '\0';

            // 格式化输出
            FormattingOutput(cache, 21, output);
        }

        // 检查是否为符号
        else if (SymbolTrigger())
        {
            printf("Find a symbol, processing...\n");
            char symbol[3];
            int index = 0;

            // 首先检查是否是双界符
            if (*current_char == '+' || *current_char == '=' ||
            *current_char == '<' || *current_char == '>')
            {
                // 指针顺移，检测下一个符号
                current_char++;

                // 检测是否是等于结尾的双界符
                if (*current_char == '=')
                {
                    // 先封装字符创
                    symbol[0] = *(current_char-1);
                    symbol[1] = *current_char;
                    symbol[2] = '\0';

                    // 记录对应种别码
                    switch (symbol[0])
                    {
                        case '+':   index = 36; break;
                        case '=':   index = 37; break;
                        case '<':   index = 38; break;
                        case '>':   index = 39; break;
                        default:    index = 0;  break;
                    }
                }

                // 检测是否是++
                else if (*(current_char-1) == '+' && *current_char == '+')
                {
                    // 封装++字符串
                    symbol[0] = symbol[1] = '+';
                    symbol[2] = '\0';
                    index = 35;
                }
                else
                {
                    // 不是双界符则要回退指针
                    current_char--;
                    
                    // 封装字符串
                    symbol[0] = *current_char;
                    symbol[1] = '\0';

                    // 记录对应种别码
                    switch(*current_char)
                    {
                        case '+':   index = 22; break;
                        case '=':   index = 27; break;
                        case '<':   index = 33; break;
                        case '>':   index = 34; break;
                    }
                }
            }

            // 检查是否是其他单界符
            else if (*current_char == '*' || *current_char == '/' ||
            *current_char == '%' || *current_char == ';' ||
            *current_char == '{' || *current_char == '}' ||
            *current_char == '(' || *current_char == ')')
            {
                // 封装字符串
                symbol[0] = *current_char;
                symbol[1] = '\0';

                // 记录对应种别码
                switch(*current_char)
                {
                    case '*':   index = 24; break;
                    case '/':   index = 25; break;
                    case '%':   index = 26; break;
                    case ';':   index = 28; break;
                    case '{':   index = 29; break;
                    case '}':   index = 30; break;
                    case '(':   index = 31; break;
                    case ')':   index = 32; break;
                    default:    index = 0;
                }
            }

            // 格式化输出
            FormattingOutput(symbol, index, output);
        }

        // 其他为错误
        else
        {
            printf("Find an error, processing...\n");
            FormattingOutput("Error", 40, output);
        }
        
        // 指针后移，方便为下个循环执行
        current_char++;
    }
    printf("Words analyzation is completed!\n");
}

int main(void)
{
    // 初始化关键字及其种码值
    initKeywords();

    // 读取用户输入的源程序文件和目标程序文件
    char source[25], result[25];
    printf("Please enter the source filename with postfix:\n");
    scanf("%s", source);
    printf("Please enter the out TEXT filename with postfix:\n");
    scanf("%s", result);
    // 这里读取的是非.txt文件，需要使用b作为读取参数，表示二进制读取
    FILE *input = fopen(source, "rb+"), *output = fopen(result, "w+");

    // 读取文件内容
    printf("Start to scan the source.\n");
    char buffer[100];
    // 行读取后拼接，便于检查
    while (fgets(buffer, 100, input) != NULL)
        strcat(big_buffer, buffer);
    current_char = big_buffer;

    // 输出提示信息并开始词法分析核心程序
    printf("Scan finished, word Analyzer starts to run...\n");
    Analyze(input, output);
    
    // 关闭目标文件
    fclose(input);
    fclose(output);

    return 0;
}
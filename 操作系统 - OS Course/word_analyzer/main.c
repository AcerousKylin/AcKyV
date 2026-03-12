#include<stdio.h>
#include<string.h>
#define MAX_KEYS 19
#define MAX_BUFFER 255

char current_char = ' ';

struct Keyword
{
    char key[10];
    int code;
} keywords[100];

char initKeys[100][10] =
{
    "main", "void", "int", "short", "long", "double", "float", "char",
    "if", "else", "switch", "case", "default", "break", "do", "while", "for", "continue",
    "struct"
};

void initKeywords()
{
    for (int i=0; i<MAX_KEYS; i++)
    {
        strcpy(keywords[i].key, initKeys[i]);
        keywords[i].code = i;
    }
}

int LetterAnalyzer()
{
    if ( (current_char >= 'a' && current_char <= 'z') ||
    (current_char >= 'A' && current_char <= 'Z') )
        return 1;
    else
        return 0;
}

int KeywordAnalyzer(char *word)
{
    int i;
    for (i=0; i<MAX_KEYS; i++)
        if ( (strcmp(keywords[i].key, word)) == 0)
            break;
    if (i < MAX_KEYS)
        return keywords[i].code;
}

int DigitAnalyzer()
{
    if (current_char >= '0' && current_char <= '9')
        return 1;
    else
        return 0;
}

int SymbolAnalyzer(FILE *input, char *symbol)
{
    if (current_char == '+' || current_char == '=' ||
    current_char == '<' || current_char == '>')
    {
        char temp = current_char;
        current_char = fgetc(input);
        if (current_char == '=')
        {
            symbol[0] = temp;
            symbol[1] = current_char;
            switch (temp)
            {
                case '+':   return 36;
                case '<':   return 38;
                case '>':   return 39;
                default:    return 0;
            }
        }
        else if (temp == '+' && current_char == '+')
        {
            symbol[0] = symbol[1] = '+';
            return 35;
        }
        else
        {
            fseek(input, -1L, SEEK_CUR);
            symbol[0] = temp;
            switch(temp)
            {
                case '+':   return 22;
                case '=':   return 27;
                case '<':   return 33;
                case '>':   return 34;
            }
        }
    }
    else if (current_char == '*' || current_char == '/' ||
    current_char == '%' || current_char == ';' ||
    current_char == '{' || current_char == '}' ||
    current_char == '(' || current_char == ')')
    {
        symbol[0] = current_char;
        switch(current_char)
        {
            case '*':   return 24;
            case '/':   return 25;
            case '%':   return 26;
            case ';':   return 28;
            case '{':   return 29;
            case '}':   return 30;
            case '(':   return 31;
            default:    return 0;
        }
    }
}

void Analyze(FILE *input, FILE *output)
{
    int index = 0;
    char cache[MAX_BUFFER];
    fprintf(output, "Word\t\tSpecies Code\n");
    while ( (current_char = fgetc(input)) != EOF )
    {
        printf("The time start right now...\n");
        // 对空格、制表符和换行符进行跳过
        if (current_char == ' ' || current_char == '\t' || current_char == '\n');

        // 对字符-标识符&关键字进行检查
        else if (current_char == '_' || LetterAnalyzer())
        {
            // 检查是否为标识符
            while (LetterAnalyzer() | DigitAnalyzer() | current_char == '_')
            {
                cache[index++] = current_char;
                current_char = fgetc(input);
            }
            // 回退判断循环结束时所用的字符
            fseek(input, -1L, SEEK_CUR);
            cache[index] = '\0';

            // 检查是否为关键字
            if (KeywordAnalyzer)
                fprintf(output, "%s\t\t%d\n", cache, KeywordAnalyzer(cache));
            else
                fprintf(output, "%s\t\t%d\n", cache, 20);
            fflush(output);
            strcpy("", cache);
            index = 0;
        }

        // 检查是否为数字
        else if (DigitAnalyzer())
        {
            while (DigitAnalyzer())
                cache[index++] = current_char;
            fseek(input, -1L, SEEK_CUR);
            strcpy("", cache);
            index = 0;
            fprintf(output, "%s\t\t%d\n", cache, 21);
            fflush(output);
        }

        // 检查是否为符号
        else if ( (index = SymbolAnalyzer(input, cache)) != 0 )
        {
            fprintf(output, "%s\t\t%d\n", cache, index);
            fflush(output);
        }

        else
        {
            fprintf(output, "%s\t\t%d\n", "Error", 40);
            fflush(output);
        }
    }
    printf("Words analyzation is completed!\n");
}

int main(void)
{
    initKeywords();
    char source[25], result[25];
    printf("Please enter the source filename with postfix:\n");
    scanf("%s", source);
    printf("Please enter the out TEXT filename with postfix:\n");
    scanf("%s", result);
    FILE *input = fopen(source, "rb+"), *output = fopen(result, "w+");

    printf("Word Analyzer starts to run...\n");
    initKeywords();
    Analyze(input, output);
    fflush(output);

    fclose(input);
    fclose(output);
    return 0;
}

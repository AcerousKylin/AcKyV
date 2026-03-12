#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
/*例1：将字符写入文件
int main(void)
{
    FILE *fp; //FILE结构体类型 定义一个文件指针
    char ch;
    //打开文件
    if ((fp = fopen("demo.txt", "w")) == NULL) //以只写方式打开文件，创建并打开文本文件，已存在的文件被覆盖
    {
        printf("Failure to open demo.txt!\n");
        exit(0);
    }
    //写文件
    //ch = getchar();
    while( ch = getchar() != '\n')
    {
        fputc(ch, fp);// 将一个字符写到文件上
        //ch = getchar();
    }
    //关闭文件
    fclose(fp);
    return 0;
}
*/

/*例3：可打印字符或ASCII码值
int main(void)
{
    FILE *fp;
    char ch; int i;
    //打开文件
    if ( ( fp = fopen("demo.bin", "wb") ) == NULL)
    {
        printf("Failure to open demo.bin!\n");
        exit(0);
    }
    //写文件
    for (i=0; i<128; i++)
    {
        fputc(i, fp);//将ASCII码值在0~127之间的字符写入文件
    }
    //关闭文件
    fclose(fp);
    //打开文件
    if ( ( fp = fopen("demo.bin", "rb") ) == NULL)
    {
        printf("Failure to open demo.bin!\n");
        exit(0);
    }
    //读文件
    //53行也可用while(!feof(fp)) //feof(fp)判断是否到文件末尾，指向末尾返回非0值，否则返回0
    while( (ch = fgetc(fp) ) != EOF)//getc(fp)从文件中读取一个字符 EOF用来判断是否到了文件末尾，到达文件末尾返回EOF(-1)
    {
        if ( isprint(ch) )//判断是否为可打印字符
        {
            printf("%c\t", ch);
        }
        else
        {
            printf("%d\t", ch);
        }
    }
    fclose(fp);
    //关闭文件
    return 0;
}
*/

/*例4：读写字符串
#define N 80
int main(void)
{
    FILE *fp; // FILE结构体类型 定义一个文件指针
    char str[N];
    // 打开文件
    if ( (fp = fopen("demo.txt", "a") ) == NULL) // 以添加方式打开文件，存在打开，不存在创建
    {
        printf("Failure to open demo.txt!\n");
        exit(0);
    }
    // 写文件
    gets(str); // 从键盘读入一个字符串
    fputs(str, fp); // 将字符串str写入文件
    // 关闭文件
    fclose(fp);
    // 打开文件
    if ( (fp = fopen("demo.txt", "r") ) == NULL)
    {
        printf("Failure to open demo.txt!\n");
        exit(0);
    }
    // 读文件
    fgets(str, N, fp); //从fp所指的文件中读出字符串，最多读N-1个字符
    puts(str);//输出到屏幕
    // 关闭文件
    fclose(fp);
    return 0;
}
*/

/*例5：按格式写文件
#define N 30
typedef struct date
{
    int year;
    int month;
    int day;
} DATE;

typedef struct student
{
    long studentID;
    char studentName[10];
    char studentSex;
    DATE birthday;
    int score[4];
    float aver;
} STUDENT;

void InputScore(STUDENT stu[], int n, int m);
void AverScore(STUDENT stu[], int n, int m);
void WritetoFile(STUDENT stu[], int n, int m);

int main(void)
{
    STUDENT stu[N];
    int n;
    printf("How many students?");
    scanf("%d", &n);
    InputScore(stu, n, 4);
    AverScore(stu, n, 4);
    WritetoFile(stu, n ,4);
    return 0;
}

void InputScore(STUDENT stu[], int n, int m)
{
    int i, j;
    for (i=0; i<n; i++)
    {
        printf("Input record %d:\n", i+1);
        scanf("%ld", &stu[i].studentID);
        scanf("%s", stu[i].studentName);
        scanf(" %c", &stu[i].studentSex); //%c前有一个空格
        scanf("%d", &stu[i].birthday.year);
        scanf("%d", &stu[i].birthday.month);
        scanf("%d", &stu[i].birthday.day);
        for (j=0; j<4; j++)
        {
            scanf("%d", &stu[i].score[j]);
        }
    }
}

void AverScore(STUDENT stu[], int n, int m)
{
    int i, j, sum;
    for (i=0; i<n; i++)
    {
        sum = 0;
        for (j=0; j<m; j++)
        {
            sum += stu[i].score[j];
        }
        stu[i].aver = (float) sum / m;
    }
}

void WritetoFile(STUDENT stu[], int n, int m)
{
    FILE *fp; //FILE结构体类型，定义一个文件指针
    int i, j;
    // 打开文件
    if ( fp = fopen("score.txt", "w") ) == NULL) //以只写方式打开文件，创建并打开文本文件，已存在的文件被覆盖
    {
        printf("Failure to open demo.txt!\n");
        exit(0);
    }
    // 写文件
    fprintf(fp, "%d\t%d\n", n, m); // 将学生人数和课程门数写入文件
    for (i=0; i<n; i++)
    {
        fprintf(fp, "%10ld %8s %3c %6d %02d %02d",
            stu[i].studentID, stu[i].studentName,
            stu[i].studentSex, stu[i].birthday.year,
            stu[i].birthday.month, stu[i].birthday.day);
        for (j=0; j<m; j++)
        {
            fprintf(fp, "%4d", stu[i].score[j]);
        }
        fprintf(fp, "%6.1f\n",stu[i].aver);
    }
    // 关闭文件
    fclose(fp);
}
*/

/*例6：按格式读文件
#define N 30
typedef struct date{
    int year;
    int month;
    int day;
}DATE;

typedef struct student{
    long studentID;
    char studentName[10];
    char studentSex;
    DATE birthday;
    int score[4];
    float aver;
}STUDENT;

void ReadfromFile(STUDENT stu[], int *n, int *m);
void PrintScore(STUDENT stu[], int n, int m);

int main(void)
{
    STUDENT stu[N];
    int n, m=4;
    ReadfromFile(stu, &n, &m);
    PrintScore(stu, n, m);
    return 0;
}

void ReadfromFile(STUDENT stu[], int *n, int *m)
{
    FILE *fp;
    int i, j;
    if ( (fp = fopen("score.txt", "r") ) == NULL)
    {
        printf("Failure to open score.txt!\n");
        exit(0);
    }
    fscanf(fp, "%d\t%d", n, m);
    for (i=0; i<*n; i++)
    {
        fscanf(fp, "%10ld", &stu[i].studentID);
        fscanf(fp, "%8s", stu[i].studentName);
        fscanf(fp, " %c", &stu[i].studentSex);
        fscanf(fp, "%4d %2d %2d", &stu[i].birthday.year,
            &stu[i].birthday.month, &stu[i].birthday.day);
        for (j=0; j<*m; j++)
        {
            fscanf(fp, "%4d", &stu[i].score[j]);
        }
        fscanf(fp, "%f", &stu[i].aver);
    }
}

void PrintScore(STUDENT stu[], int n, int m)
{
    int i, j;
    for (i=0; i<n; i++);
    {
        printf("%10ld", stu[i].studentID);
        printf("%8s", stu[i].studentName);
        printf("%3c", stu[i].studentSex);
        printf("%6d/%02d/%02d", stu[i].birthday.year,
            stu[i].birthday.month, stu[i.birthday.day);
        for (j=0; j<m; j++)
        {
            printf("%4d", stu[i].score[j]);
        }
        printf("%6.1f\n", stu[i].aver);
    }
}
*/

/*例7：按数据块读写文件*/
#define N 30
typedef struct date
{
    int year;
    int month;
    int day;
} DATE;

typedef struct student
{
    long studentID;
    char studentName[10];
    char studentSex;
    DATE birthday;
    int score[4];
    float aver;
} STUDENT;

void InputScore(STUDENT stu[], int n, int m);
void AverScore(STUDENT stu[], int n, int m);
void WritetoFile(STUDENT stu[], int n, int m);
int ReadfromFile(STUDENT stu[]);
void PrintScore(STUDENT stu[], int n, int m);

int main(void)
{
    STUDENT stu[N];
    int n, m=4;
    printf("How many student?");
    scanf("%d", &n);
    InputScore(stu, n, m);
    AverScore(stu, n, m);
    WritetoFile(stu, n, m);
    n = ReadfromFile(stu);
    PrintScore(stu, n, m);
    return 0;
}

void InputScore(STUDENT stu[], int n, int m)
{
    int i, j;
    for (i=0; i<n; i++)
    {
        printf("Input record %d:\n", i+1);
        scanf("%ld", &stu[i].studentID);
        scanf("%s", stu[i].studentName);
        scanf(" %c", &stu[i].studentSex);
        scanf("%d", &stu[i].birthday.year);
        scanf("%d", &stu[i].birthday.month);
        scanf("%d", &stu[i].birthday.day);
        for (j=0; j<4; j++)
        {
            scanf("%d", &stu[i].score[j]);
        }
    }
}

void AverScore(STUDENT stu[], int n, int m)
{
    int i, j ,sum;
    for (i=0; i<n; i++)
    {
        sum = 0;
        for (j=0; j<m; j++)
        {
            sum += stu[i].score[j];
        }
        stu[i].aver = (float) sum / m;
    }
}

void WritetoFile(STUDENT stu[], int n, int m);
{
    FILE *fp; //FILE结构体类型，定义一个文件指针
    int i, j;
    //打开文件
    if ( (fp = fopen("score.txt", "w") )= NULL)
    {
        printf("Failure to open score.txt!\n");
        exit(0);
    }
    //
    fwrite(stu, sizeof(STUDENT), n, fp); //
    //
    fclose(fp);
}

int ReadfromFile(STUDENT stu[])
{
    FILE *fp;
    int i, j;
    if ( (fp = fopen("score.txt", "r") ) ==NULL )
    {
        printf("Failure to open score.txt!\n");
        exit(0);
    }
    //
    for (i=0; !feof(fp); i++)
    {
        fread(&stu[i], sizeof(STUDENT), 1, fp); //
    }
    //
    fclose(fp);
    printf("Total student is %d.\n", i-1);
}

void PrintScore(STUDENT stu[], int n , int m)
{
    int i, j;
    for (i=0l i<n; i++)
    {
        printf("%10ld", stu[i].studentID);
        printf("%8s", stu[i].studentName);
        printf("%3c", stu[i].studentSex);
        printf("%6d/%02d/%02d", stu[i].birthday.year,
            stu[i].birthday.month, stu[i].birthday.day);
        for (j=0; j<m; j++)
        {
            printf("%4d", stu[i]/score[j]);
        }
        printf("%6.1f\n", stu[i].aver);
    }
}
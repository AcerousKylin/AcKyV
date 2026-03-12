#include <stdio.h>
#include <stdlib.h>
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

void InputScore(STUDENT stu[],int n,int m);
void AverScore(STUDENT stu[],int n,int m);
void WritetoFile(STUDENT stu[],int n,int m);
int ReadfromFile(STUDENT stu[]);
void PrintScore(STUDENT stu[],int n,int m);

int main()
{
    STUDENT stu[N];
    int n,m=4;
    printf("How many student?");
    scanf("%d",&n);
    InputScore(stu,n,m);
    AverScore(stu,n,m);
    WritetoFile(stu,n,m);
    n=ReadfromFile(stu);
    PrintScore(stu,n,m);
    return 0;
}

void InputScore(STUDENT stu[],int n,int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("Input record %d:\n",i+1);
        scanf("%ld",&stu[i].studentID);
        scanf("%s",stu[i].studentName);
        scanf(" %c",&stu[i].studentSex);//%c前有一个空格
        scanf("%d",&stu[i].birthday.year);
        scanf("%d",&stu[i].birthday.month);
        scanf("%d",&stu[i].birthday.day);
        for(j=0;j<4;j++)
        {
            scanf("%d",&stu[i].score[j]);
        }
    }
}

void AverScore(STUDENT stu[],int n,int m)
{
    int i,j,sum;
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=0;j<m;j++)
        {
            sum+=stu[i].score[j];
        }
        stu[i].aver = (float)sum/m;
    }
}
void WritetoFile(STUDENT stu[],int n,int m)
{
    FILE *fp; //FILE结构体类型 定义一个文件指针
    int i,j;
    //打开文件
    if((fp=fopen("score.txt","w"))==NULL)//以只写方式打开文件
    {
        printf("Failure to open demp.txt!\n");
        exit(0);
    }
    //写文件
    fwrite(stu,sizeof(STUDENT),n,fp);//按数据块写文件
    //关闭文件
    fclose(fp);
}

int ReadfromFile(STUDENT stu[])
{
    FILE *fp;
    int i,j;
    if((fp=fopen("score.txt","r"))==NULL)//以读方式打开文本文件
    {
        printf("Failure to open score.txt!\n");
        exit(0);
    }
    //读文件
    for(i=0;!feof(fp);i++)
    {
        fread(&stu[i],sizeof(STUDENT),1,fp);//按数据块读文件
    }
    //关闭文件
    fclose(fp);
    printf("Total students is %d.\n",i-1);
    return i-1;
}
void PrintScore(STUDENT stu[],int n,int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("%10ld",stu[i].studentID);
        printf("%8s",stu[i].studentName);
        printf("%3c",stu[i].studentSex);
        printf("%6d/%02d/%02d",stu[i].birthday.year,stu[i].birthday.month,stu[i].birthday.day);
        for(j=0;j<m;j++)
        {
            printf("%4d",stu[i].score[j]);
        }
        printf("%6.1f\n",stu[i].aver);
    }
}

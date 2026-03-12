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

void ReadfromFile(STUDENT stu[],int *n,int *m);
void PrintScore(STUDENT stu[],int n,int m);

int main()
{
    STUDENT stu[N];
    int n,m=4;
    ReadfromFile(stu,&n,&m);
    PrintScore(stu,n,m);
    return 0;
}

void ReadfromFile(STUDENT stu[],int *n,int *m)
{
    FILE *fp;
    int i,j;
    if((fp=fopen("score.txt","r"))==NULL)//以读方式打开文本文件
    {
        printf("Failure to open score.txt!\n");
        exit(0);
    }
    fscanf(fp,"%d\t%d",n,m);//从文件中读出学生人数和课程门数
    for(i=0;i<*n;i++)
    {
        fscanf(fp,"%10ld",&stu[i].studentID);
        fscanf(fp,"%8s",stu[i].studentName);
        fscanf(fp," %c",&stu[i].studentSex);//%c前有一个空格
        fscanf(fp,"%4d%2d%2d",&stu[i].birthday.year,&stu[i].birthday.month,&stu[i].birthday.day);
        for(j=0;j<*m;j++)
        {
            fscanf(fp,"%4d",&stu[i].score[j]);
        }
        fscanf(fp,"%f",&stu[i].aver);
    }
    fclose(fp);
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

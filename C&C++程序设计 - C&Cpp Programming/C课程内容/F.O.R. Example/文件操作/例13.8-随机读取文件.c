#include <stdio.h>
#include <stdlib.h>

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

void SearchinFile(char FileName[],long k);

int main()
{
    long k;
    printf("Input the searching record number:");
    scanf("%ld",&k);
    SearchinFile("score.txt",k);
    return 0;
}

//函数功能：从FileName中查找并显示第k条记录的数据
void SearchinFile(char fileName[],long k)
{
    FILE *fp;
    int j;
    STUDENT stu;
    if((fp=fopen(fileName,"r"))==NULL)
    {
        printf("Failure to open %s!\n",fileName);
        exit(0);
    }
    //fseek(fp,(k-1)*sizeof(STUDENT),SEEK_SET);
    fread(&stu,sizeof(STUDENT),1,fp);

    printf("%10ld%8s%3c%6d/%02d/%02d",stu.studentID,stu.studentName,stu.studentSex,stu.birthday.year,stu.birthday.month,stu.birthday.day);
    for(j=0;j<4;j++)
    {
        printf("%4d",stu.score[j]);
    }
    printf("%6.1f\n",stu.aver);
    fclose(fp);
}

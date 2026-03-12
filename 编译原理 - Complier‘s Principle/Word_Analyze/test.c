#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char big_buffer[1024];

int main(void)
{
    char buffer[100];
    FILE *input, *output;
    if (fopen_s(&input, "demo1.c", "r+") != 0)
        return -1;
    if (fopen_s(&output, "token.txt", "w+") != 0)
        return -1;

    int i=0;
    while (fgets(buffer, 100, input) != NULL)
    {
        printf("buffer:\n%s\n", buffer);
        strcat(big_buffer, buffer);
        fputs(buffer, output);
    }
    printf("big buffer:\n%s\n");

    char result[20];
    sprintf(result, "%s\t\t%s\n", "lol", "26");
    printf("%s\n", result);
    fputs(result, fopen("token.txt", "w+"));

    return 0;
}
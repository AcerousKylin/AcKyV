// I-输入 O-输出 T-总和 L-最大 M-最小 A-平均 F-查找 R-逆置 S-排序 V-填充 Q-退出 > _
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/* 你编写的主函数将被嵌在这里 */

int main(void)
{
    double number[100];
    int length, signal=1;
    printf("数组尺寸: ");
    scanf("%d", &length);
    getchar();
    do
    {
        printf("I-输入 O-输出 T-总和 L-最大 M-最小 A-平均 F-查找 R-逆置 S-排序 V-填充 Q-退出 > ");
        char input;
        scanf("%c", &input);
        switch (input)
        {
            case 'I':
            case 'i':
            {
                int i;
                printf("输入: ");
                for (i=0; i<length; i++)
                    scanf("%lf", &number[i]);
                break;
            }
            case 'O':
            case 'o':
            {
                int i;
                printf("输出: ");
                for (i=0; i<length; i++)
                {
                    printf("%.1lf", number[i]);
                    if (i<length-1)
                        printf(", ");
                }
                printf("\n");
                break;
            }
            case 'T':
            case 't':
            {
                int i;
                double sum;
                for (i=0; i<length; i++)
                    sum += number[i];
                printf("总和: %.1lf\n", sum);
                break;
            }
            case 'L':
            case 'l':
            {
                int i;
                double max=number[0];
                for (i=0; i<length; i++)
                    if (max<number[i])
                        max = number[i];
                printf("最大值: %.1lf\n", max);
                break;
            }
            case 'M':
            case 'm':
            {
                int i;
                double min=number[0];
                for (i=0; i<length; i++)
                    if (min>number[i])
                        min = number[i];
                printf("最小值: %.1lf\n", min);
                break;
            }
            case 'A':
            case 'a':
            {
                int i;
                double sum;
                for (i=0; i<length; i++)
                    sum += number[i];
                printf("平均值: %.1lf\n", sum/length);
                break;
            }
            case 'F':
            case 'f':
            {
                int i, flag=0;
                double target;
                printf("查找: ");
                scanf("%lf", &target);
                for (i=0; i<length; i++)
                {
                    if (number[i]==target)
                    {
                        printf("查找成功! 下标: %d\n", i);
                        flag = 1;
                    }
                }
                if (!flag)
                    printf("查找失败!\n");
                break;
            }
            case 'R':
            case 'r':
            {
                int i;
                double temp;
                for (i=0; i<length/2; i++)
                {
                    temp = number[i];
                    number[i] = number[length-i-1];
                    number[length-i-1] = temp;
                }
                printf("逆置\n");
                break;
            }
            case 'S':
            case 's':
            {
                int i, j;
                double temp;
                for (i=0; i<length; i++)
                {
                    for (j=i; j<length; j++)
                    {
                        if (number[i]>number[j])
                        {
                            temp = number[i];
                            number[i] = number[j];
                            number[j] = temp;
                        }
                    }
                }
                printf("排序\n");
                break;
            }
            case 'V':
            case 'v':
            {
                int i;
                double stuff;
                printf("填充值: ");
                scanf("%lf", &stuff);
                for (i=0; i<length; i++)
                    number[i] = stuff;
                break;
            }
            case 'Q':
            case 'q':
                signal = 0;
                break;
            default :
                printf("不正确的选项!\n");
                break;
        }
    }while(signal);
    printf("退出\n");
    return 0;
}

// if-else版:

int main(void)
{
    double number[100];
    int length, signal=1;
    printf("数组尺寸: ");
    scanf("%d", &length);
    getchar();
    do
    {
        printf("I-输入 O-输出 T-总和 L-最大 M-最小 A-平均 F-查找 R-逆置 S-排序 V-填充 Q-退出 > ");
        char input;
        scanf("%c", &input);
        getchar();

        if (input=='I' || input=='i')
        {
            int i;
            printf("输入: ");
            for (i=0; i<length; i++)
                scanf("%lf", &number[i]);
        }

        else if (input=='O' || input=='o')
        {
            int i;
            printf("输出: ");
            for (i=0; i<length; i++)
            {
                printf("%.1lf", number[i]);
                if (i<length-1)
                    printf(", ");
            }
            printf("\n");
        }

        else if (input=='T' || input=='t')
        {
            int i;
            double sum;
            for (i=0; i<length; i++)
                sum += number[i];
            printf("总和: %.1lf\n", sum);
        }

        else if (input=='L' && input=='l')
        {
            int i;
            double max=number[0];
            for (i=0; i<length; i++)
                if (max<number[i])
                    max = number[i];
            printf("最大值: %.1lf\n", max);
        }

        else if (input=='M' || input=='m')
        {
            int i;
            double min=number[0];
            for (i=0; i<length; i++)
                if (min>number[i])
                    min = number[i];
            printf("最小值: %.1lf\n", min);
        }

        else if (input=='A' || input=='a')
        {
            int i;
            double sum;
            for (i=0; i<length; i++)
                sum += number[i];
            printf("平均值: %.1lf\n", sum/length);
        }

        else if (input=='F' || input=='f')
        {
            int i, flag=0;
            double target;
            printf("查找: ");
            scanf("%lf", &target);
            for (i=0; i<length; i++)
            {
                if (number[i]==target)
                {
                    printf("查找成功! 下标: %d\n", i);
                    flag = 1;
                }
            }
            if (!flag)
                printf("查找失败!\n");
        }

        else if (input=='R' || input=='r')
        {
            int i;
            double temp;
            for (i=0; i<length/2; i++)
            {
                temp = number[i];
                number[i] = number[length-i-1];
                number[length-i-1] = temp;
            }
            printf("逆置\n");
        }

        else if (input=='S' || input=='s')
        {
            int i, j;
            double temp;
            for (i=0; i<length; i++)
            {
                for (j=i; j<length; j++)
                {
                    if (number[i]>number[j])
                    {
                        temp = number[i];
                        number[i] = number[j];
                        number[j] = temp;
                    }
                }
            }
                printf("排序\n");
        }

        else if (input=='V' || input=='v')
        {
            int i;
            double stuff;
            printf("填充值: ");
            scanf("%lf", &stuff);
            for (i=0; i<length; i++)
                number[i] = stuff;
        }

        else if (input=='Q' || input=='q')
            signal = 0;

        else
            printf("不正确的选项!\n");

    }while(signal);
    printf("退出\n");
    return 0;
}
#include<stdio.h>
struct Circle{
    int x; // 圆中心点的横坐标
    int y; // 圆中心点的纵坐标y
    float r; // 圆的半径
};

void computearea(struct Circle *p);

void main(）
{
    struct Circle *c;
    computearea(c);
}

/* 请在这里填写答案 */

void computearea(struct Circle *p)
{
    float area;
    scanf("%d %d %f", &p->x, &p->y, &p->r);
    area = p->r * p->r * 3.14;
    printf("%.2f", area);
}
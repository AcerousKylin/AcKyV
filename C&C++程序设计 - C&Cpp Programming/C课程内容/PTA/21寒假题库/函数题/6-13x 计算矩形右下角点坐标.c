struct rectangle{
   int x;
   int y;
   int width;
   int height;
};
void main()
{
    struct rectangle *rec;
    compute(rec);
}

/* 请在这里填写答案 */

#include<stdlib.h>

void compute(struct rectangle *p)
{
    p = (struct rectangle *)malloc(sizeof(int)*4);
    float mid_x, mid_y;
    scanf("%d %d %d %d", &p->x, &p->y, &p->width, &p->height);
    mid_x = 0.5 * (p->x +  p->width);
    mid_y = 0.5 * (p->y + p->height);
    printf("%.0f %.0f", mid_x, mid_y);
    free(p);
}
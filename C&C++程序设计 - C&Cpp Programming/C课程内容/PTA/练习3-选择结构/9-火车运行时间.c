// 题目版
#include<stdio.h>
int main(void)
{
    int h1, h2, m1, m2, it1, it2, tt1, tt2, t;
    scanf("%d %d", &it1, &it2);
    h1  = it1/100;
    h2  = it2/100;
    m1  = it1%100;
    m2  = it2%100;
    tt1 = h1*60+m1;
    tt2 = h2*60+m2;
    t   = tt2-tt1;
    printf("%02d:%d", t/60, t%60);
    return 0;
}

// 实用版
#include<stdio.h>
int main(void)
{
    int st, et, sh, eh, sm, em, hg, mg;
    scanf("%d %d", &st, &et);
    hg = et/100-st/100;
    mg = et%100-st%100;
    if (mg<0) printf("%02d:%02d",hg-1, mg+60);
    else
    {
        if (mg>0, mg<60)
        {
        printf("%02d:%02d", hg, mg);
        }
        else
        {
        printf("%02d:%02d", hg+1, mg-60);
        }
    }
   return 0;
}

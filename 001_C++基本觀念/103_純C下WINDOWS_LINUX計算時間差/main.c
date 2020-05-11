#include <stdio.h>
#include <sys/timeb.h>
#include <stdlib.h>
#if defined(WIN32)
# define  TIMEB    _timeb
# define  ftime    _ftime
typedef __int64 TIME_T;
#else
#define TIMEB timeb
typedef long long TIME_T;
#endif
int time_interval()
{
    struct TIMEB ts1,ts2;
    TIME_T t1,t2;
    int ti;
    ftime(&ts1);//开始计时
    //do some work
    {
        int i;
        for(i=0;i<100000;i++)
        {
            int *p=malloc(10000);
            int *q=malloc(10000);
            int *s=malloc(10000);
            int *t=malloc(10000);
            free(p);
            free(q);
            free(s);
            free(t);
        }
    }
    ftime(&ts2);//停止计时
    t1=(TIME_T)ts1.time*1000+ts1.millitm;
    printf("t1=%lld\n",t1);
    t2=(TIME_T)ts2.time*1000+ts2.millitm;
    printf("t2=%lld\n",t2);
    ti=t2-t1;//获取时间间隔，ms为单位的

    return ti;
}
int main()
{
    int ti=time_interval();
    printf("time interval=%d\n",ti);
}

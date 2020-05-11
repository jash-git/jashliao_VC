#include <stdio.h>
#include <stdlib.h>

int cmp (const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int main ()
{  
    const int N = 10;
    int buf[N+1], *a = buf+1, v, i = N;
    
    while (i--) scanf ("%d", a+i);    
    qsort (a, N, sizeof(int), cmp);
    
    for (i=0; i<=N; ++i) v=a[i-1], printf (i?v&1?"":" %d":"\n°¸¼Æ", v);
    for (i=0; i<=N; ++i) v=a[i-1], printf (i?v&1?" %d":"":"\n©_¼Æ", v);
	system("PAUSE");
}
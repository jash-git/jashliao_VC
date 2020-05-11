#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10];
    int d=0.0;
    int i,j;
    for(i=0;i<10;i++)
    {
      j=&a[i];
      d+=j;
      printf("%ld\t%d\n",j,d);

    }
    return 0;
}

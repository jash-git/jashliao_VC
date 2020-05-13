#include <stdio.h>
#include <stdlib.h>
long int_Reversion(int data)
{
    int Multiple;
    int i;
    Multiple=1;
    i=0;
    do
    {
        i++;
        Multiple=Multiple*10;
    }while(Multiple<=data);
    if(i==1)
    {
        return data;
    }
    else
    {
        return ((data%10)*(Multiple/10))+int_Reversion(data/10);
    }
}
int main()
{
    long a;
    printf("input a int=\t");
    scanf("%d",&a);
    printf("%ld->%ld\n",a,int_Reversion(a));
    return 0;
}

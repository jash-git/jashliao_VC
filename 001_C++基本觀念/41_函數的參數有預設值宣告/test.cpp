#include <stdio.h>
int function(int a,int b,int c=0);
main()
{
	printf("1+2=%d\n",function(1,2));
	printf("2-1=%d\n",function(2,1,1));
}
int function(int a,int b,int c)
{
	if(c!=0)
		return (a-b);
	else
		return (a+b);
}
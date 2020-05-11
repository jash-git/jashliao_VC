#include <stdio.h>
void main()
{
	int a,b,c;
	try
	{
		a=10;
		c=0;
		scanf("%d",&b);
		c=a/b;
		printf("output is %d\n",c);
	}
	catch(...)
	{
		printf("Get error\n");
	}
}
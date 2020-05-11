#include <stdio.h>
int get_value(int d)
{
	if(d>1)
	{
		return (d*(get_value(d-1)));
	}
	else
	{
		return d;
	}
}
void main()
{
	int data;
	data=get_value(5);
	printf("%d\n",data);
}
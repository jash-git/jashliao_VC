#include <stdio.h>
void main(void)
{
	int x=0;
	while(1)
	{
		if(x%3==1 && x%5==3 && x%7==2)
		{
			printf("%d\n",x);
			break;
		}
		x++;
	}
}

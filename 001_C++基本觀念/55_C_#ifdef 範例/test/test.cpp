// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#define debug_printf 1;

int main(int argc, char* argv[])
{
	int i,j;
	double sum,y;
	sum=0.0;
	for(i=1;i<=20;i++)
	{
		#ifdef debug_printf
			printf("i loop=%d\t",i);
		#endif
		y=0;
		for(j=0;j<=i;j++)
		{
			y+=j;
		}
		#ifdef debug_printf
			printf("y=%f\n",y);
		#endif
		sum+=1/y;
		#ifdef debug_printf
			printf("sum=%f\n",sum);
		#endif
	}
	printf("sum=1/1+1/(1+2)+...1/(1+2+...+20) \t");
	printf("Ans=%f\n",sum);
	return 0;
}

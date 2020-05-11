#include <stdio.h>
#include <stdlib.h>
/*
C語言：全域變數，局部區域變數，區域靜態變數，x++，++x整合觀念範例
*/
int x=5;
void f(int x)
{
	printf ("%d\n", x++);
}
void g(void)
{
	static int x=0;
	printf ("%d\n", x++);//區域變數x輸出後+1
}
void main ()
{
	printf ("%d\n", ++x);//全域變數x先+1後輸出---->5+1=6
	{
		int x=4;
		printf ("%d\n" ,x++);//區域變數x輸出後+1---->4
	}
	g();//靜態區域變數x輸出後+1---->0
	f(x);//全域變數x輸出後+1---->6
	g();//靜態區域變數x輸出後+1---->1
}
/*
6
4
0
6
1
*/

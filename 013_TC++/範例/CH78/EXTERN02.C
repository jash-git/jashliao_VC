/* program extern02.c */
/* demo */

#include "file3.h"
int x=1,y=2;
main()
{
	void sub1(int);
	void sub2(int *);
	int a=3, b=4, x=5;
	printf("a=%2d,b=%2d,x=%2d,y=%2d\n",a,b,x,y);
	sub1( a );
	printf("a=%2d,b=%2d,x=%2d,y=%2d\n",a,b,x,y);
	sub2( &b );
	printf("a=%2d,b=%2d,x=%2d,y=%2d\n",a,b,x,y);
	sub3();
	printf("a=%2d,b=%2d,x=%2d,y=%2d\n",a,b,x,y);
}
void sub1(int x)
{
	int i=6;
	x = 7;
	printf("x=%2d,i=%2d,y=%2d\n",x,i,y);
}
void sub2(int *a)
{
	int n=8,p=9;
	*a = 10;
	printf("n=%2d,p=%2d,a=%2d,x=%2d,y=%2d\n",n,p,*a,x,y);
}

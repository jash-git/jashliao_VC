/* program demo01.c */

#include <math.h>
#define  pi	3.14159
float radius;
main()
{
	float calc( int );
	int area;
	printf("Enter area : ");
	scanf("%d",&area);
	radius = calc( area );
	printf("The radius = %f\n",radius);
}
float calc( int x )
{
	float r;
	r = sqrt(x/(2*pi));
	return( r );
}

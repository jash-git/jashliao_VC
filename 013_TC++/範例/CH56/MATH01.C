/* program math01.c */
/* demo include  math.h */

#include <math.h>
#define  radian 0.01745329
main()
{
	double x,y,degree;
	y = 300.0;
	degree =  12.0;
	x = sin( degree * radian ) * y;
	printf("The high = %6.2fm\n",x);
}

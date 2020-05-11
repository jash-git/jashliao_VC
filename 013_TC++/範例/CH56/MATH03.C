/* program math03.c */
/* demo  compute x^n  by pow function */

#include <math.h>
main()
{
	double b,e;
	printf("Enter base : ");
	scanf(" %lf",&b);
	printf("Enter exponent : ");
	scanf(" %lf",&e);
	printf("Power(%lf,%lf)=%lf\n",b,e,pow(b,e) );
}

/* program math04.c */
/* demo compute x^n by log and exp function */

#include <math.h>
main()
{
	double b,e;
	printf("Enter base : ");
	scanf(" %lF",&b);
	printf("Enter exponent : ");
	scanf(" %lF",&e);
	printf("Power(%6.2lf,%6.2lf)=%10.2lf\n",
					b,e,exp((log(b) * e) ));
}

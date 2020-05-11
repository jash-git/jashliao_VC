/* program math05.c */
/* demo sqrt() function using */

#include <math.h>
main()
{
	int a,b,c,d;
	double x1,x2;
	printf("Enter equation coef: a,b,c : ");
	scanf("%d %d %d",&a,&b,&c);
	d = b * b - 4 * a * c;
	if ( d == 0 )
	{
		x1 = x2 = (double) (-b / ( 2 * a ));
		printf("x1 = x2 = %lf\n",x1);
	}
	else if ( d > 0 )
	{
		x1 = ( -b + sqrt( d )) / ( 2 * a );
		x2 = ( -b - sqrt( d )) / ( 2 * a );
		printf("x1 = %lf\n",x1);
		printf("x2 = %lf\n",x2);
	}
	else
	{
		printf("x1=%lf + %lfi\n",(double) -b/(2*a),
						(double) sqrt(fabs(d))/(2*a));
		printf("x2=%lf - %lfi\n",(double) -b/(2*a),
						(double) sqrt(fabs(d))/(2*a));
	}
}

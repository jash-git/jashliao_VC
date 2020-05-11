#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* exp */
/*double log(double x)x 的自然對數 ln(x)，x > 0*/
/*y = x^n
ln(y) = n*ln(x)
y = exp(n*ln(x))*/
int main ()
{
	float z,y,x,n;
	y=0.0;
	x=0.0;
	n=0.0;
	z=0.0;
	printf("y = x^n\n");
	printf("input x=\t");
	scanf("%f",&x);
	printf("input n=\t");
	scanf("%f",&n);
	y=exp(n*log(x));
	z=pow(x,n);
	printf("exp(n*ln(x))=%f\n",y);
	printf("pow(x,n)=%f\n",z);
	return 0;
}

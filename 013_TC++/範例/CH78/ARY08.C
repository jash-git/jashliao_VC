/* program ary08.c */
/* demo array using for working area */

#include <math.h>
main()
{
	int x[10] = {70,62,75,83,69,92,85,65,77,61};
	float avg,total=0.0;
	double dev,sum=0.0;
	int i;
	for ( i=0; i<10; i++ )
	    total += x[i];
	avg = total / 10.0;
	for ( i=0 ; i<10 ; i++ )
	    sum += fabs(avg-x[i]);
	dev = sum / 10.0;
	printf("Total=%6.2f,avg=%6.2f,derviation=%6.2f\n",
		total,avg,dev);
}

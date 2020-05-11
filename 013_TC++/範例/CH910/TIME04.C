/* program time04.c */
/* demo get execution time from processor */

#include <time.h>
main()
{
	unsigned long i,t,count = 100000;
	double a,b,c,d;
	clock_t ticksnow;
	for ( i=1 ; i<=count ; i++ )
	{
		a = ( double )( i+i );
		b = ( double )( i-i );
		c = ( double )( i*2 );
		d = ( double )( i/2 );
	}
	/* get current clock ticks */
	if (( ticksnow = clock() ) == ( clock_t ) -1 )
	{
		printf("processor time not available !\n");
		abort();
	}
	t = ( unsigned long ) ticksnow / CLK_TCK;
	printf("100000 loops ran for %u seconds\n",t );
}

/* program time05.c */
/* demo get execution time from system clock */

#include <time.h>
main()
{
	unsigned long i,count = 100000;
	double a,b,c,d,tused;
	time_t tstart,tend;
	/* get the time before do loop */
	time( &tstart );
	for ( i=1 ; i<=count ; i++ )
	{
		a = ( double )( i+i );
		b = ( double )( i-i );
		c = ( double )( i*2 );
		d = ( double )( i/2 );
	}
	/* get the time after loop */
	time( &tend );
	tused = difftime( tend,tstart );
	printf("100000 loops ran for %u seconds\n",(unsigned)tused);
}

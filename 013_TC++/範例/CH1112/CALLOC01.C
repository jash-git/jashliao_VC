/* program calloc01.c */

#include <stdlib.h>
main()
{
	int i;
	int *p;
	p = ( int * ) calloc( 5 , sizeof( int ) );
	if ( ! p )
	{
		printf(" Out of memory.\n");
		exit( 1 );
	}
	for ( i=0 ; i<5 ; i++ )
	{
		*(p+i) = i * 5;
		printf("%4d",*(p+i) );
	}
	printf("\n");
	free( p );	/* free memory */
}

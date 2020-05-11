/* program calloc02.c */
/* demo reallocation memory */

#include <stdlib.h>
main()
{
	int i;
	int *p,*q;
	p = ( int * ) calloc( 5,sizeof( int ));
	if ( ! p )
	{
		printf(" Out of memory\n");
		exit( 1 );
	}
	for ( i=0 ; i<5 ; i++ )
		*(p+i) = i * 5;
	q = ( int * ) realloc( p,20 );
	if ( ! q )
	{
		printf(" Out of memory\n");
		exit( 1 );
	}
	for ( i=5 ; i<10 ; i++ )
		*(q+i) = i * 5;
	for ( i=0 ; i<10 ; i++ )
		printf("%4d",*(q+i));
	printf("\n");
	free( q );
}

/* program link05.c */
/* demo memory request */

#include <stdlib.h>
main()
{
	char *p;
	p = malloc( 80 );
	if ( p == NULL )
	{
		printf("out of memory.\n");
		exit( 1 );
	}
	printf("Enter a string : ");
	gets( p );
	puts( p );
	free( p );
}

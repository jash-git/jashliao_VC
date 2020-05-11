/* program reg01.c */
/* demo register variable characteristic */

#include <stdlib.h>
unsigned int i;
unsigned int loop;
main()
{
	register unsigned int j;
	long t;
	t = time(NULL);
	for ( loop=0 ; loop<10 ; loop++ )
		for ( i=0; i<65000 ; i++)
			/* dummy loop */;
	printf("Time for non-register loop : %ld\n",
						 time(NULL)-t);
	t = time(NULL);
	for ( loop=0 ; loop<10 ; loop++ )
		for ( j=0 ; j<65000 ; j++ )
			/* dummy loop */;
	printf("Time for register loop : %ld\n",time(NULL)-t);
}

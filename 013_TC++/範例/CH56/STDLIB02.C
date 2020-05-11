/* program stdlib02.c */
/* demo abort() function using */

#include <stdlib.h>
main()
{
	printf("Press Q to quit ");
	for ( ; ; )
		if ( getche() == 'Q' )
			abort();
}

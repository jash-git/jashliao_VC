/* program conio04.c */
/* demo interrupt by kbhit */

#include <conio.h>
main()
{
	int i;
	for ( ; ; )
	{
		printf("Test the interrupt by press any key...\n");
		/* dummy loop for delay display */
		for ( i=0 ; i<200 ; i++ );
		if ( kbhit() )
			break;
	}
}

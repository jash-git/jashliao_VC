/* program time03.c */
/* demo get time and output */

#include <time.h>
#include <stdio.h>
main()
{
	struct tm *t;
	time_t tt;
	tt = time( NULL );
	t = gmtime( &tt );
	printf("The date and time is %s\n",asctime( t ) );
}

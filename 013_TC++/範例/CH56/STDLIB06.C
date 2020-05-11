/* program  stdlib06.c */
/* demo rand() application */

#include <stdlib.h>
#include <time.h>
main()
{
	long ltime;
	int stime,i,num;
	ltime = time( NULL );
	stime = ( int ) ltime / 2;
	srand( stime );
	for ( i=0 ; i<10 ; i++ )
	{
		num = rand() % 6 +1;
		printf("%3d",num);
	}
	printf("\n");
}

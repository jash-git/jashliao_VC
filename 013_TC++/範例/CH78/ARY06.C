/* program ary06.c */
/* demo array using for marking */

#include <stdlib.h>
#include <time.h>
main()
{
	int mark[6] = {0,0,0,0,0,0};
	int i,num,t=0,c=0;
	randomize();
	do
	{
		num = random( 6 );
		t++;
		if ( mark[ num ] == 0 )
		{
			mark[ num ] = 1;
			c++;
		}
	}
	while ( c < 6 );
	printf("Total toss %d times \n",t);
}

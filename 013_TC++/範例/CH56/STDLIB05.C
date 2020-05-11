/* program stdlib05.c */
/* demo rand() application */

#include <stdlib.h>
main()
{
	int i,num;
	for ( i=0 ; i<10 ; i++ )
	{
		num = rand() % 6 + 1;
		printf("%3d ",num);
	}
	printf("\n");
}

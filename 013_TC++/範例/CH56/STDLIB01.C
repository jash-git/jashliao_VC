/* program stdlib01.c */
/* demo abs() function using */

#include <stdlib.h>
main()
{
	int i,j,k;
	for ( i=-3 ; i<=3 ; i++ )
	{
		for ( k=0 ; k<=abs(i) ; k++ )
			printf("%c",' ');
		for ( j=abs(i)-3 ; j<=3-abs(i) ; j++ )
			printf("%d",abs(j));
		printf("\n");
	}
}

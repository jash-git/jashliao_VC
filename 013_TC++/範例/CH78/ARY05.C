/* program ary05.c */
/* demo ary using for counting */

#define n	100
#include <stdlib.h>
main()
{
	int c[6] = {0,0,0,0,0,0};
	unsigned int s;
	int num,i;
	printf("Enter 0-65535 for seed : ");
	scanf("%d",&s);
	srand(s);	/* initialize for random generator */
	for ( i=1 ; i<=n ; i++ )
	{
		num = rand() % 6;
		c[num]++;
	}
	for ( i=0; i<6 ; i++ )
		printf("%d  ==> %3d times\n",i+1,c[i]);
}

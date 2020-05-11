/* program io08.c */
/* demo i/o for double and long type */

#include <stdio.h>

main()
{
	long i;
	unsigned long j;
	double d;
	printf("Enter long integer :");
	scanf("%D",&i);
	printf("Enter unsigned long : ");
	scanf("%U",&j);
	printf("Enter double :");
	scanf("%lE",&d);
	printf("long i = %ld\n",i);
	printf("unsigned long j = %lu\n",j);
	printf("double d = %le\n",d);
}

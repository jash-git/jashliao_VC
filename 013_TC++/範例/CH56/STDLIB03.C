/* program stdlib03.c */
/* demo itoa() function using */

#include <stdlib.h>
main()
{
	int num,b;
	char *s;
	printf("Enter base : ");
	scanf("%d",&b);
	printf("Enter integer value : ");
	scanf("%d",&num);
	itoa( num , s , b );
	printf("Base = 10 , Value = %d\n",num);
	printf("Base = %d , Value = %s\n",b,s);
}

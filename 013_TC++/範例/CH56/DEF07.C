/* program def07.c */
/* demo #include using */

#include "mydef.h"
main()
{
	int a;
	char ch;
	printf("Enter one integer value : ");
	scanf("%d",&a);
	printf("Enter one character : ");
	scanf(" %c",&ch);
	printf("circle area = %10.4f\n",Area(a) );
	printf("g(%d) = 2x^2 - 4x +5 = %d\n",a,g(a) );
	if ( odd(a) )
		printf("%d is odd number\n");
	else
		printf("%d is even number\n");
	printf("%d C degree = %6.2f F degree\n",a,fr(a) );
	printf("%d F degree = %6.2f C degree\n",a,ce(a) );
	if ( Is_Lower( ch ) )
		printf("%c is lower character\n",ch);
	if ( Is_Upper( ch ) )
		printf("%c is upper character\n",ch);
}

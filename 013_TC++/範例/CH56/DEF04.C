/* program def04.c */
/* demo define function */

#define odd(x)	((x) %2 == 1 ) ? 1 : 0
main()
{
	int x;
	printf("Enter one integer value : ");
	scanf(" %d",&x);
	if ( odd(x) )
		printf("%d is odd number.\n",x);
	else
		printf("%d is even number.\n",x);
}

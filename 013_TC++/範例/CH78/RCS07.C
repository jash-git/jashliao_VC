/* program rcs07.c */
/* demo recursive call for fibonacci sequence */

main()
{
	int n;
	int fib(int);
	printf("Enter one integer value: ");
	scanf("%d",&n);
	printf("fib(%d)=%d\n",n,fib( n ));
}
int fib( int n )
{
	if ( n <= 2 )
		return( 1 );
	else
		return( fib( n-1 ) + fib( n-2 ));
}

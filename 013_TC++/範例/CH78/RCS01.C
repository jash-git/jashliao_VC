/* program rcs01.c*/
/* demo recursive call for sum */

main()
{
	int s,n;
	int sum(int);
	printf("Enter one integer value : ");
	scanf("%d",&n);
	s = sum( n );
	printf("The sum of 1 to %d = %d\n",n,s );
}
int sum( int n )
{
	if ( n == 1 )
		return( 1 );
	else
		return( sum( n - 1 ) + n );
}

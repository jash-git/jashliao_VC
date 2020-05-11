/* program fun04.c */
/* demo parameter passing */

main()
{
	int n;
	long f;
	long fact(int);
	printf("Enter one value : ");
	scanf("%d",&n);
	f = fact( n );
	printf("The factorial of %d = %ld\n",n,f);
}
long fact( int n )
{
	int i;
	long f=1;
	for ( i=1 ; i<=n ; i++ )
		f *= i;
	return( f );
}

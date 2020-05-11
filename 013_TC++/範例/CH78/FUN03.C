/* program fun03.c */
/* demo function return */

main()
{
	long fact(void);
	long f;
	f = fact();
	printf("The factorial = %ld\n",f);
}
long fact(void)
{
	int i,n;
	long f=1;
	printf("Enter one value : ");
	scanf("%d",&n);
	for ( i=1 ; i<=n ; i++ )
		f *= i;
	return( f );
}

/* program while05.c */
/* demo for while nesting */

main()
{
	double f=1.0;
	long i,n,e=0;
	printf("key in a positive integer :");
	scanf("%lD",&n);
	for ( i=1 ; i<=n ; i++ )
	{
		f *= i;
		while ( f >= 10.0 )
		{
			f /= 10.0;
			e++;
		}
	}
	printf("%ld! = %16.14lfE+%ld\n",n,f,e);
}

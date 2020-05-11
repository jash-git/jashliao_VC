/* program while04.c */
/* demo while nesting loop using */

main()
{
	int a,b;
	printf("Enter two integer value :");
	scanf("%d %d",&a,&b);
	while ( a != b )
	{
		while ( a > b )
			a -= b;
		while ( b > a )
			b -= a;
	}
	printf("gcd = %d \n",a);
}

/* program if02.c */
/* demo if else statement */

main()
{
	int a,b;
	printf("Enter two integer value :");
	scanf("%d %d",&a,&b);
	while ( a != b )
		if ( a > b )
			a -= b;
		else
			b -= a;
	printf("gcd = %d \n",a);
}

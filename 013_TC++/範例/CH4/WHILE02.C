/* program while02.c */
/* demo while long using */

main()
{
	int a,b,r;
	printf("Enter two integer value: ");
	scanf("%d %d",&a,&b);
	while ( b != 0 )
	{
		r = a % b;
		a = b;
		b = r;
	}
	printf("gcd = %d\n",a);
}

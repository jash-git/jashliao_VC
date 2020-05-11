/* program if05.c */
/* demo if else statement */

main()
{
	int n,d,prime=1;
	printf("Enter a positive integer :");
	scanf("%d",&n);
	d = 2;
	while (( d < n/2 ) && prime )
		if ( n % d == 0  )
			prime = 0;
		else d++;
	if ( prime )
		printf("Prime number\n");
	else printf("Not a prime number\n");
}

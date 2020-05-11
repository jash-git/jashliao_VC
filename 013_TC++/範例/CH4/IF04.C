/* program if04.c */
/* demo nesting if statement */

main()
{
	int n,i,s=0;
	printf("Enter a positive integer value : ");
	scanf("%d",&n);
	for( i=1 ; i<=n/2 ; i++ )
		if  ( n % i == 0 )
			s += i;
	if ( s == n )
			printf("Perfect number\n");
	else  if ( s > n )
					printf("Abundant number\n");
				else
					printf("Deficient number\n");
}

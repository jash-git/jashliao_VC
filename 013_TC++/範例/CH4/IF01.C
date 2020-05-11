/* program if01.c */
/* demo if statement using */

main()
{
	int i,n;
	printf("Enter one integer value :");
	scanf("%d",&n);
	for ( i=1 ; i<=n ; i++ )
		if ( n%i == 0 )
			printf("%d  ",i);
	printf("\n");
}

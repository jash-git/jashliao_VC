/* program for04.c */
/* demo nesting for loop */

main()
{
	int i,j,k;
	for ( i=1 ; i<10 ; i++ )
	{
		for ( j=10-i ; j>0 ; j-- )
			printf(" ");
		for ( k=1 ; k<=i ; k++ )
			printf("%c",'*');
		printf("\n");
	}
}

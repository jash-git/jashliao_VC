/* program rcs03.c */
/* demo recursive call for reverse digit */

main()
{
	int n;
	void reverse_digit( int );
	printf("Enter one 4-digits number : ");
	scanf("%d",&n);
	reverse_digit( n );
	printf("\n");
}
void reverse_digit( int n )
{
	if ( n != 0 )
	{
		printf("%d",n%10 );
		reverse_digit( n/10 );
	}
}

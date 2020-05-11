/* program rcs05.c */
/* demo recursive call for decimal to binary */

main()
{
	int x;
	void bin( int );
	printf("Enter decimal value : ");
	scanf("%d",&x);
	bin( x );
	printf("\n");
}
void bin( int x )
{
	if ( x != 0 )
	{
		bin( x >> 1 );
		printf("%d", x%2);
	}
}

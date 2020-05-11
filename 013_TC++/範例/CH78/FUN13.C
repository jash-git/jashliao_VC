/* program fun13.c */
/* demo side effect */

int z=10;
main()
{
	int sneaky(int);
	int a;
	a = sneaky(z);
	printf("a=%d  z=%d\n",a,z);
	z = 10;
	a = sneaky( 10 ) * sneaky( z );
	printf("a=%d  z=%d\n",a,z);
	z = 10;
	a = sneaky( z ) * sneaky( 10 );
	printf("a=%d  z=%d\n",a,z);
}
int sneaky( int x )
{
	z -= x;
	return( x * x );
}

/* program fun11.c */
/* demo parameter passing */

main()
{
	int sub(int *,int *,int);
	int a=0, b=1, c=2;
	printf("a=%d  b=%d  c=%d\n",a,b,c);
	a = sub( &b , &b , b+c );
	printf("a=%d  b=%d  c=%d\n",a,b,c);
}
int sub( int *x , int *y , int z )
{
	*y = z;
	return( *x + z );
}

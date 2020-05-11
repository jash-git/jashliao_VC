/* program fun09.c */
/* demo passing by address */

main()
{
	void liar( int *a , int *b );
	int x = -1;
	liar( &x, &x );
	printf("X = %d\n",x);
}
void liar( int *a, int *b )
{
	*a = - *b;
	*b = - *b;
}

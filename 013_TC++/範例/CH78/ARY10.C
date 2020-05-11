	/* program ary10.c */
/* demo array using for sorting */

#define n	10
main()
{
	int x[n] = { 70,62,75,83,69,92,85,65,77,61};
	int i,j,t;
	void swap( int * , int * );
	for ( i=0 ; i<n-1 ; i++ )
		for ( j=i+1 ; j<n ; j++ )
			if ( x[i] > x[j] )
				swap( &x[i], &x[j] );
	for ( i=0 ; i<n ; i++ )
		printf("x[%d] = %d\n",i,x[i]);
}
void swap( int *a , int *b )
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

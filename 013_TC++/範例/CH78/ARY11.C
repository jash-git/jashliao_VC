/* program ary11.c */
/* demo array as parameter for passing */

#define n 10
main()
{
	int x[n];
	void inputarray( int * );
	void sort( int * );
	void printarray( int * );
	inputarray( x );
	sort( x );
	printf("After sorting :\n");
	printarray( x );
}
void inputarray( int a[] )
{
	int i;
	for ( i=0 ; i<n ; i++ )
	{
		printf("a[%d] = ",i);
		scanf("%d",&a[i]);
	}
}
void sort( int a[] )
{
	int i,j;
	void swap( int * , int * );
	for ( i=0 ; i<n-1 ; i++ )
		for ( j=i+1 ; j<n ; j++ )
			if ( a[i] > a[j] )
				swap( &a[i] , &a[j] );
}
void printarray( int x[] )
{
	int i;
	for (i=0; i<n ; i++ )
	{
		if (i%5 == 0)
			 printf("\n");
		printf(" x[%d] =%4d",i,x[i]);
	}
}
void swap( int *c , int *d )
{
	int t;
	t = *c;
	*c = *d;
	*d = t;
}

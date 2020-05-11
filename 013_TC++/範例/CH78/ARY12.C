/* program ary12.c */
/* demo array using by structure programming */

#define n	4
main()
{
	int num,dif,org,max,min,i;
	int x[n];
	void distribute( int * , int );
	void sort( int * );
	void assembly( int * , int * , int * );
	printf("Enter one 4-digit number : ");
	scanf("%d",&num);
	printf("  num   max   min   dif  \n");
	printf("-------------------------\n");
	do
	{
		org = num;
		distribute( x , org );
		sort( x );
		max = min = 0;
		assembly( x , &max , &min );
		dif = max - min;
		printf("%6d%6d%6d%6d\n",org,max,min,dif);
		num = dif;
	}
	while( org != dif );
} /* end of main */
/* distribute subroutine */
void distribute( int x[] , int num )
{
	int i;
	for ( i=0 ; i<n ; i++ )
	{
		x[i] = num % 10;
		num /= 10;
	}
}
/* sort subroutine */
void sort( int x[] )
{
	int i,j;
	void swap( int * , int * );
	for ( i=0 ; i<n-1 ; i++ )
		for ( j=i+1 ; j<n ; j++ )
			if ( x[i] > x[j] )
				swap( &x[i] , &x[j] );
}
/* swap subroutine */
void swap( int *a , int *b )
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
/* assembly subroutine */
void assembly( int x[] , int *max , int *min )
{
	int i;
	for (i=0 ; i<n ; i++ )
	{
		*min = *min * 10 + x[i];
		*max = *max * 10 + x[ n-i-1 ];
	}
}

/* program ary04.c */
/* demo reflex matrix */

#define m	3
#define n	4
int c[m][n] = { {1,2,3,4},
								{5,6,7,8},
								{9,10,11,12} };
main()
{
	void swap(int *, int *);
	int i,j;
	for ( i=0 ; i<m ; i++ )
		for ( j=0 ; j<n/2 ; j++ )
				swap(&c[i][j],&c[i][n-j-1]);
	for ( i=0 ; i<m ; i++ )
	{
		for ( j=0 ; j<n ; j++ )
			printf("%3d",c[i][j]);
		printf("\n");
	}
}
void swap(int *x, int *y)
{
	int t;
	t = *x;
	*x = *y;
	*y = t;
}

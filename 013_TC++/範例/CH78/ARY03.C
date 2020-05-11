/* program ary03.c */
/* demo two dimensional array */

#define	m		3
#define n		4
main()
{
	int x[m][n] = { {1,2,3,4},
									{5,6,7,8},
									{9,10,11,12}  };
	int i,j;
	for ( i=0 ; i<m ; i++ )
	{
		for ( j=0 ; j<n ; j++ )
			printf("%3d",x[i][j]);
		printf("\n");
	}
}

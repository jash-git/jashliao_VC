/* program ary13.c */
/* demo two dimensional array using */
/* magic matrix */

#define max_n	20
main()
{
	int x[max_n][max_n];
	int i,j,k,n;
	do
	{
		printf("Enter array size (3-19) : ");
		scanf("%d",&n);
	}
	while ( (n>19) || (!(n % 2)) || (n<3));
	/* fill zero into array */
	for (i=1;i<=n;i++)
	    for (j=1;j<=n;j++)
		 x[i][j]=0;
	i = 1;
	j = ( n+1 ) / 2;
	x[i][j] = 1;
	for ( k=2 ; k<=n*n ; k++ )
	{
		i--;
		j++;
		if ( (i<1) && (j>n) )
		{
			i = 2;
			j = n;
		}
		else if ( i<1 )
			i = n;
		     else if ( j>n )
			     j = 1;
			  else if ( x[i][j] != 0 )
				  {
					i += 2;
					j--;
				  }
		x[i][j] = k;
	}
	for ( i=1 ; i<=n ; i++ )
	{
		for ( j=1 ; j<=n ; j++ )
			printf("%4d",x[i][j]);
		printf("\n");
	}
}

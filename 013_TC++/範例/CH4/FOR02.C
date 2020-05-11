/* program for02.C */
/* demo for loop using */

main()
{
	int i,j;
	for ( i=1 ; i<10 ; i++ )
	{
		for ( j=1 ; j<10 ; j++ )
			printf("%d*%d=%2d ",i,j,i*j);
		printf("\n");
	}
}

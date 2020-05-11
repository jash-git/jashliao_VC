/* program ary07.c */
/* demo array using for substitution */

main()
{
	char c[4] = { 6,3,4,5 };
	char *d[13] ={ "A","2","3","4","5","6","7",
								 "8","9","10","J","Q","K" };
	int i,j;
	for ( i=0 ; i<4 ; i++ )
	{
		for ( j=0 ; j<13 ; j++ )
			printf("%c %-3s",c[i],d[j]);
		printf("\n");
	}
}

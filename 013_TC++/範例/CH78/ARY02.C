/* program ary02.c */
/* demo fibonacci number */

#define n	10
main()
{
	int f[n];
	int i;
	f[0] = 1;
	f[1] = 1;
	for ( i=2 ; i<n ; i++ )
		f[i] = f[i-1] + f[i-2];
	for ( i=0 ; i<n ; i++ )
		printf("%5d",f[i]);
	printf("\n");
}

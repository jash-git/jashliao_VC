/* program arr0c.c*/
/* demo array pass by address */

main()
{
	void twotimes(int *);
	int x[6]={1,2,3,4,5,6};
	int i;
	twotimes( x );
	for ( i=0 ; i<6 ; i++ )
		printf("%3d",x[i]);
	printf("\n");
}
void twotimes(int x[])
{
	int i;
	for ( i=0 ; i<6 ; i++ )
		x[i] *= 2;
}

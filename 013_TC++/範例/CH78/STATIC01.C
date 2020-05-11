/* program static01.c */
/* demo without static delcaration */

main()
{
	int sum(void);
	int i;
	for ( i=1 ; i<=3 ; i++ )
		printf("%dth time = %d\n",i,sum() );
}
int sum(void)
{
	int x=0;
	x++;
	return( x );
}

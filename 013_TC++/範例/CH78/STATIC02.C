/* program static02.c */
/* demo with static declaration */

main()
{
	int sum(void);
	int i;
	for ( i=1 ; i<=3 ; i++ )
		printf("%dth time = %d\n",i,sum());
}
int sum(void)
{
	static int x=0;
	x++;
	return( x );
}

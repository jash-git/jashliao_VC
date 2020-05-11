/* program ptr0c.c */
/* print array address */

main()
{
	int x[6] = {10,20,30,40,50,60};
	int *p;
	int i;
	p=x;
	for ( i=0 ; i<6 ; i++ )
		printf("%u  ",&x[i]);
	printf("\n");
	for ( i=0 ; i<6 ; i++ )
		printf("%u  ",p+i);
	printf("\n");
}

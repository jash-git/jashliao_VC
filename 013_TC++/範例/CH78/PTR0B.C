/* program ptr0b.c */
/* demo pointer array access */

main()
{
	int x[6]={10,20,30,40,50,60};
	int *p;
	int i;
	p=x;   /* array start address assign to pointer */
	for ( i=0 ; i<6 ; i++ )
		printf("%3d",*(p+i));
	printf("\n");
	for ( i=0 ; i<6 ; i++ )
		*(p+i)=0;
	for ( i=0 ; i<6 ; i++ )
		printf("%3d",*(p+i));
	printf("\n");
}

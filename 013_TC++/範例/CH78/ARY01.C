/* program ary01.c */
/* demo one dimension array input and output */

#define n	4
main()
{
	int x[n];
	int i,*p=x;
	for ( i=0 ; i<n ; i++ )
	{
		printf("x[%d] = ",i);
		scanf("%d",p+i);
	}
	for ( i=0 ; i<n ; i++ )
		printf("x[%d] = %d\n",i,x[i]);
}

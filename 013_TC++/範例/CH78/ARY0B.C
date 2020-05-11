/* program ary0b.c */
/* demo array as parameter */

main()
{
	void print(int *);
	int x[6]={611,310,521,823,42,95};
	print(x);
}
void print(int a[])
{
	int i;
	for ( i=0 ; i<6 ; i++ )
		printf("%4d",a[i]);
	printf("\n");
}

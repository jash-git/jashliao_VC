/* program fun08.c */
/* demo passing by address */

main()
{
	void swap(int *,int *);
	int x,y;
	printf("Enter two value : ");
	scanf("%d %d",&x,&y);
	printf("X = %d  Y = %d\n",x,y);
	swap( &x, &y );
	printf("X = %d  Y = %d\n",x,y);
}
void swap(int *a,int *b)
{
	int t;
	 t = *a;
	*a = *b;
	*b = t;
}

/* program rcs06.c */
/* demo recursive call for nCr */

main()
{
	int n,r;
	int comb(int,int);
	do
	{
		printf("Enter n,r(n>=r;n,r>=0): ");
		scanf("%d %d",&n,&r);
	}
	while ((n<r) || (r<0) || (n<0)) ;
	printf("C(%d,%d)=%d\n",n,r,comb(n,r));
}
int comb(int n,int r)
{
	if ( (n==r) || (r==0))
		return( 1 );
	else
		return(comb(n-1,r)+comb(n-1,r-1));
}

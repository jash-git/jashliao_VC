/* program rcs02.c*/
/* demo recursive call for gcd */

main()
{
	int x,y;
	int gcd(int,int);
	printf("Enter two integer value : ");
	scanf("%d %d",&x,&y);
	printf("gcd(%d,%d) = %d\n",x,y,gcd(x,y));
	printf("lcm(%d,%d) = %d\n",x,y,x*y/gcd(x,y));
}
int gcd(int a,int b)
{
	if ( b == 0)
		return( a );
	else
		return( gcd( b , a % b ) );
}

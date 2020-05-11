/* program fun05.c */
/* demo function  sequential call */

main()
{
	int gcd(int,int);
	int lcm(int,int);
	int a,b,c;
	printf("Enter three integer value : ");
	scanf("%d %d %d",&a,&b,&c);
	printf("The gcd of %d, %d & %d is %d\n",
					a,b,c,gcd(gcd(a,b),c));
	printf("The lcm of %d, %d & %d is %d\n",
					a,b,c,lcm(lcm(a,b),c));
}
int gcd( int x , int y )
{
	int r;
	while ( y != 0  )
	{
		r = x % y;
		x = y;
		y = r;
	}
	return( x );
}
int lcm( int x , int y )
{
	return( x * y / gcd( x , y ) );
}

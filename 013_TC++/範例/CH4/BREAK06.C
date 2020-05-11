/* program break06.c */
/*  demo continue statement using */

main()
{
	float x,t,s=0.0;
	do
	{
		 printf("Enter one value ( >1 ) : ");
		 scanf("%f",&x);
	}
	while ( x <= 1 );
	t = 1 / x;
	while ( t >= 1E-05 )
	{
		s += t;
		t /= x;
		continue;
	}
	printf("Total = %9.5f\n",s);
}

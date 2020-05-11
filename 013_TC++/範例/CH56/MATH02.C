/* program math02.c */
/* demo compute x^n by loop */

main()
{
	float power( float,float );
	float b,e;
	printf("Enter base : ");
	scanf("%f",&b);
	printf("Enter exponent : ");
	scanf("%f",&e);
	printf("Power(%6.2f,%6.2f ) = %10.2f\n",b,e,power(b,e));
}
float power( float x , float n )
{
	int i;
	float f=1.0;
	for( i=1 ; i<=n ; i++ )
		f *= x;
	return( f );
}

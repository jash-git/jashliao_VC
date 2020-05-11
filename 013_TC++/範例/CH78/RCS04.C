/* program rcs04.c */
/* demo recursive call for taylor's sequence */

float x;
main()
{
	float s;
	float taylor( float );
	do
	{
		printf("Enter a real ( >1 ) : ");
		scanf("%f",&x);
	}
	while ( x <= 1 );
	s = taylor( 1 / x );
	printf("sum = %9.5f\n",s);
}
float taylor(float t)
{
	if ( t < 1e-5 )
		return( 0 );
	else
		return( (taylor( t / x ) + t) );
}

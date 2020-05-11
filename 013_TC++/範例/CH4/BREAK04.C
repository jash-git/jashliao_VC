/* program break04.c */
/* demo break satement using */

main()
{
	int m=0;
	float loan,interest,rate,payment;
	printf("Enter loan, year rate: ");
	scanf("%f  %f",&loan,&rate);
	printf("Enter payment per month: ");
	scanf("%f",&payment);
	do
	{
		interest = ( loan * rate ) / 12;
		loan -= ( payment - interest );
		m++;
		if ( loan <= 0 )
			break;
	}
	while( 1 );
	printf("After %d months the loan will be clear\n",m);
}

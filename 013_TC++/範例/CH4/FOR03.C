/* program for03.c */
/* demo for loop using */

main()
{
	int i;
	long int f=1;
	for ( i=1 ; i<25 ; ++i )
	{
		f *=2;
		printf("The %2dth powers of 2 ===>%8ld\n",i,f);
	}
}
